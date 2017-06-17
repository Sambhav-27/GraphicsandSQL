use db_world;

-- create table test(
-- 	id int not null auto_increment primary key
-- );

-- select * from test;

-- create table student3(
-- 	name varchar(10),
-- 	stno int not null auto_increment primary key,
-- 	class varchar(10),
-- 	major int
-- );

-- create table course(
-- 	cname varchar(20),
-- 	cno int not null auto_increment primary key,
-- 	credit int,
-- 	dept varchar(20)
-- );

-- create table section2(
-- 	sid int,
-- 	cno int,
-- 	semester varchar(10),
-- 	year date,
-- 	instructor varchar(20),
-- 	primary key(sid)
-- );

-- create table grade_report(
-- 	stno int,
-- 	sid int,
-- 	grade varchar(10),
-- 	primary key(stno)
-- );

-- create table prerequisite(
-- 	cno int,
-- 	preno int,
-- 	primary key(cno, preno)
-- );




-- insert into student2(name, class, major) values('john', 'coe1', 'cs'), ('ram', 'ece1', 'ece');
-- insert into course(cname, credit, dept) values('ds', 4, 'coe'), ('dbms', 4, 'coe');
-- insert into section2(sid, cno, semester, year, instructor) values(1, 1, 'vi',19980505, 'jain'), (2, 2, 'iii', 19980403, 'sam'), (3, 3, 'vi', 20050202, 'jain');
-- insert into grade_report(stno, sid, grade) values(1, 1, 'A'), (2, 2,'B');
-- insert into prerequisite(cno, preno) values (1,5),(1,4),(1,3),(2,1);



-- insert into course(cname, credit, dept) values('electronnics', 4, 'ece');
-- insert into student2(name, class, major) values('sambhav', 'coe1', 'ice'), ('sam', 'ece1', 'ece');
-- insert into grade_report(stno, sid, grade) values(3, 1, 'C'), (4, 2,'A');

-- insert into course(cname, credit, dept) values('cs', 4, 'coe');


-- insert into student3(name, class, major) values('john', 'coe1', 1), ('ram', 'ece1', 2);
-- insert into student3(name, class, major) values('sambhav', 'coe1', 3), ('sam', 'ece1', 4);

-- insert into section2(sid, cno, semester, year, instructor) values(4, 1, 'vi',19980505, 'jain');



select * from student2;
select * from student3;
select * from course;
select * from section2;
select * from grade_report;
select * from prerequisite;


select distinct course.cname
from course, section2
where course.cno=section2.cno and section2.instructor='jain' and (YEAR(section2.year)=1998 || YEAR(section2.year)=2005);


select student2.name, student2.major
from student2, grade_report
where student2.stno= grade_report.stno and grade_report.grade not in ('A');

-- select section2.sid 
-- from section2, student2
-- where YEAR(section2.year)<2004



-- select name, cname, course.cno, credit, semester, year,grade
-- from student3, course, section2, grade_report
-- where student3.stno= grade_report.stno and student3.major=course.cno and course.cno=section2.cno and YEAR(section2.year<2017)
-- and course.cno in (select major from course,student3 where cname='cs' and course.cno=student3.major);




-- select stno
-- from section2, student3
-- where student3.major=(select cno from course where cname='cs') and YEAR(section2.year)<2017;

select *
from student3,  grade_report
where student3.stno=grade_report.stno  and
student3.stno in (select stno
from section2, student3
where student3.major=(select cno from course where cname='cs') and YEAR(section2.year)<2017);
















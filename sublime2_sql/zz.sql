 -- create database projectdb2;
	use projectdb2;

-- drop table if exists projectdb2.seats_required;
-- drop table if exists projectdb2.seats_confirmed;
-- drop table if exists projectdb2.seats_waiting;
-- drop table if exists projectdb2.ticket;
-- drop table if exists projectdb2.address;
-- drop table if exists projectdb2.user; 
-- drop table if exists projectdb2.schedule;
-- drop table if exists projectdb2.fares;
-- drop table if exists projectdb2.intermediate_stations;
-- drop table if exists projectdb2.distance;
-- drop table if exists projectdb2.train;
-- drop table if exists projectdb2.train2;
-- drop table if exists projectdb2.station;




-- create table user(
-- 		uid int not null auto_increment primary key,
-- 		email varchar(20) unique not null,
-- 		dob date,		
-- 		phn varchar(12),
-- 		fname varchar(20),
-- 		lname varchar(20),
-- 		password varchar(20)
-- );


-- CREATE TABLE `station` (
--   `stno` int(11) NOT NULL AUTO_INCREMENT,
--   `stname` varchar(20) DEFAULT NULL,
--   PRIMARY KEY (`stno`)
-- ) ;

-- CREATE TABLE `train` (
--   `trainno` varchar(10) NOT NULL,
--   `src` int(11) DEFAULT NULL,
--   `des` int(11) DEFAULT NULL,
--   `rdate` date,
--   `ac1seats` int(11) DEFAULT NULL,
--   `ac2seats` int(11) DEFAULT NULL,
--   `ac3seats` int(11) DEFAULT NULL,
--   `sleeper1seats` int(11) DEFAULT NULL,
--   `sleeper2seats` int(11) DEFAULT NULL,
--   PRIMARY KEY (`trainno`, `rdate`),
--   FOREIGN KEY (`src`) REFERENCES `station` (`stno`) ON DELETE CASCADE,
--   FOREIGN KEY (`des`) REFERENCES `station` (`stno`) ON DELETE CASCADE
-- ) ;

-- CREATE TABLE `train2` (
--   `trainno` varchar(10) NOT NULL,
--   `src` int(11) DEFAULT NULL,
--   `des` int(11) DEFAULT NULL,
--   `rdate` date,
--   `ac1seats` int(11) DEFAULT NULL,
--   `ac2seats` int(11) DEFAULT NULL,
--   `ac3seats` int(11) DEFAULT NULL,
--   `sleeper1seats` int(11) DEFAULT NULL,
--   `sleeper2seats` int(11) DEFAULT NULL,
--   PRIMARY KEY (`trainno`, `rdate`),
--   FOREIGN KEY (`src`) REFERENCES `station` (`stno`) ON DELETE CASCADE,
--   FOREIGN KEY (`des`) REFERENCES `station` (`stno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `ticket` (
--   `pnr` varchar(11) NOT NULL,
--   `uid` int(11) DEFAULT NULL,
--   `trainno` varchar(10) DEFAULT NULL,
--   `src_u` int(11) DEFAULT NULL,
--   `des_u` int(11) DEFAULT NULL,
--   `totalfare` int(11) DEFAULT NULL,
--   `depart_date` date DEFAULT NULL,
--   `depart_time` time DEFAULT NULL,
--   PRIMARY KEY (`pnr`),
--   FOREIGN KEY (`uid`) REFERENCES `user` (`uid`) ON DELETE CASCADE,
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE,
--   FOREIGN KEY (`src_u`) REFERENCES `station` (`stno`) ON DELETE CASCADE,
--   FOREIGN KEY (`des_u`) REFERENCES `station` (`stno`) ON DELETE CASCADE
-- );




-- CREATE TABLE `address` (
--   `uid` int(11) NOT NULL AUTO_INCREMENT,
--   `hno` int(11) DEFAULT NULL,
--   `strtno` int(11) DEFAULT NULL,
--   `city` varchar(20) DEFAULT NULL,
--   `pin` varchar(7) DEFAULT NULL,
--   PRIMARY KEY (`uid`),
--   FOREIGN KEY (`uid`) REFERENCES `user` (`uid`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `distance` (
--   `stno1` int(11) NOT NULL DEFAULT '0',
--   `stno2` int(11) NOT NULL DEFAULT '0',
--   `dist` float DEFAULT NULL,
--   PRIMARY KEY (`stno1`,`stno2`),
--    FOREIGN KEY (`stno1`) REFERENCES `station` (`stno`) ON DELETE CASCADE,
--    FOREIGN KEY (`stno2`) REFERENCES `station` (`stno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `fares` (
--   `trainno` varchar(10) NOT NULL DEFAULT '',
--   `class` varchar(20) NOT NULL,
--   `price` int(11) DEFAULT NULL,
--   PRIMARY KEY (`trainno`,`class`),
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `intermediate_stations` (
--   `trainno` varchar(10) NOT NULL DEFAULT '',
--   `stno` int(11) NOT NULL DEFAULT '0',
--   PRIMARY KEY (`trainno`,`stno`),
--    FOREIGN KEY (`stno`) REFERENCES `station` (`stno`) ON DELETE CASCADE,
--    FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `schedule` (
--   `trainno` varchar(10) NOT NULL DEFAULT '',
--   `stno` int(11) NOT NULL DEFAULT '0',
--   `arrivaltime` time DEFAULT NULL,
--   `departuretime` time DEFAULT NULL,
--   PRIMARY KEY (`trainno`,`stno`),
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE,
--   FOREIGN KEY (`stno`) REFERENCES `station` (`stno`) ON DELETE CASCADE
-- ); 


-- CREATE TABLE `seats_confirmed` (
--   `class` varchar(20) NOT NULL DEFAULT '',
--   `pnr` varchar(11) NOT NULL DEFAULT '',
--   `trainno` varchar(10) DEFAULT NULL,
--   `seats_no` varchar(5) NOT NULL DEFAULT '',
--   PRIMARY KEY (`class`,`pnr`,`seats_no`),
--   FOREIGN KEY (`pnr`) REFERENCES `ticket` (`pnr`) ON DELETE CASCADE,
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `seats_required` (
--   `class` varchar(20) NOT NULL DEFAULT '',
--   `pnr` varchar(11) NOT NULL DEFAULT '',
--   `trainno` varchar(10) DEFAULT NULL,
--   `count` int(11) DEFAULT NULL,
--   PRIMARY KEY (`class`,`pnr`),
--   FOREIGN KEY (`pnr`) REFERENCES `ticket` (`pnr`) ON DELETE CASCADE,
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE
-- ) ;


-- CREATE TABLE `seats_waiting` (
--   `class` varchar(20) NOT NULL DEFAULT '',
--   `pnr` varchar(11) NOT NULL DEFAULT '',
--   `trainno` varchar(10) DEFAULT NULL,
--   `waitno` int(11) NOT NULL DEFAULT '0',
--   PRIMARY KEY (`class`,`pnr`,`waitno`),
--   FOREIGN KEY (`pnr`) REFERENCES `ticket` (`pnr`) ON DELETE CASCADE,
--   FOREIGN KEY (`trainno`) REFERENCES `train` (`trainno`) ON DELETE CASCADE
-- ) ;


 -- Create table govid(
 --      eno varchar(10) PRIMARY KEY,
 --      depart varchar(10)
 --  ) ;

 -- insert into govid values('9560', 'safety'),('1234', 'personnel'),('4321', 'safety');

-- insert into station values (1, 'new delhi'), (2, 'kerala'), (3, 'jaipur'), (4, 'bhopal'), (5, 'indore');
-- insert into train values ('dl123', 1, 2, 20170501, 10,10,10,20,20), ('mi123', 3, 1, 20170502, 11,11,11,22,22);
-- insert into train2 values ('dl123', 1, 2, 20170501, 10,10,10,20,20), ('mi123', 2, 1, 20170502, 11,11,11,22,22);
-- insert into schedule values ('dl123', 1, 150202, 150404), ('mi123', 1, 110202, 130101), ('dl123', 2, 150202, 150404),('dl123', 3, 150202, 150404);
-- insert into fares values ('dl123', 'ac1seats', 50), ('dl123', 'ac2seats', 40), ('dl123', 'ac3seats', 30), ('dl123', 'sleeper1seats', 20), ('dl123', 'sleeper2seats', 10);
-- insert into distance values (1,2,200), (1,3,300),(2,3,250);
-- insert into intermediate_stations values('dl123', 4), ('dl123', 5);
-- insert into intermediate_stations values('dl123', 1), ('dl123', 2);
-- insert into distance values (1,4,220), (1,5,230);
  -- insert into station values (6, 'rajkot');
  -- insert into intermediate_stations values ('mi123', 3),('mi123', 1),('mi123', 6);
  -- insert into schedule values('dl123', 4, 170404, 170505);
select * from station;
select * from train;
select * from schedule;
select * from fares;
select * from distance;
select * from intermediate_stations;
select * from user;
select * from ticket;
select * from seats_required;

select * from seats_confirmed;
select * from seats_waiting;




-- DELETE  from seats_waiting
-- where class='ac1seats' and pnr ='U86BOBI6' and trainno ='dl123'
-- limit 10;

-- update seats_waiting s, ticket
--   set waitno= waitno+1000
--   where (waitno <=5 ) 
--   and (ticket.pnr = s.pnr  and  depart_date = '20170501' and class ='ac1seats');

-- update seats_waiting s, ticket
--   set waitno= waitno-1
--   where (waitno < 11 and waitno > 5) 
--   and (ticket.pnr = s.pnr  and  depart_date = '20170501' and class ='ac1seats');

--   update seats_waiting s, ticket
--   set waitno= waitno-1000
--   where (waitno>1000) 
--   and (ticket.pnr = s.pnr  and  depart_date = '20170501' and class ='ac1seats');



-- DELETE from seats_confirmed;
-- DELETE from seats_waiting;
-- DELETE from seats_required;

-- 4

-- "update seats_waiting s, ticket set waitno = waitno-" +wcount+" where (waitno >" +maxwait+") and (ticket.pnr =  s.pnr  and  depart_date = \'"+ depart_date+"\' and class=\'ac1seats\');";

-- select i.trainno from station s, intermediate_stations i where s.stname='bhopal' and s.stno=i.stno;

-- select  i.trainno from station s, intermediate_stations i where s.stname='new delhi' and s.stno=i.stno;

-- select trainno,departuretime from schedule where trainno in (select trainno from train
-- where trainno in (select i.trainno from station s, intermediate_stations i where s.stname='bhopal' and s.stno=i.stno) and trainno in(select  i.trainno from station s, intermediate_stations i where s.stname='new delhi' and s.stno=i.stno)
-- ) and stno=(select stno from station where stname='bhopal');


-- select trainno from train where trainno in (select i.trainno from station s, intermediate_stations i where s.stname=\'" + src +"\' and s.stno=i.stno) and trainno in (select i.trainno from station s, intermediate_stations i where s.stname=\'" + des +"\' and s.stno=i.stno)


select * from govid;










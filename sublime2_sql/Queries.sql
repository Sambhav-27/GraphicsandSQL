use projectdb2;

-- delete from station;
-- delete from distance;
-- delete from train;
-- delete from train2;
-- delete from fares;
-- delete from intermediate_stations;
-- delete from schedule;

-- insert into station(stno,stname) values ('1','new delhi');
-- insert into station(stno,stname) values ('2','kolkata');
-- insert into station(stno,stname) values ('3','chennai');
-- insert into station(stno,stname) values ('4','mumbai');
-- insert into station(stno,stname) values ('5','bhopal');
-- insert into station(stno,stname) values ('6','kanyakumari');
-- insert into station(stno,stname) values ('7','rourkela');
-- insert into station(stno,stname) values ('8','indore');
-- insert into station(stno,stname) values ('9','vadodara');
-- insert into station(stno,stname) values ('10','chandigarh');
-- insert into station(stno,stname) values ('11','hyderabad');
-- insert into station(stno,stname) values ('12','begaluru');
-- insert into station(stno,stname) values ('13','srinagar');
-- insert into station(stno,stname) values ('14','shimla');

-- insert into distance values ('1','2','200');
-- insert into distance values ('1','3','300');
-- insert into distance values ('1','4','200');
-- insert into distance values ('1','5','250');
-- insert into distance values ('1','6','600');
-- insert into distance values ('1','7','700');
-- insert into distance values ('1','8','800');
-- insert into distance values ('1','9','900');
-- insert into distance values ('1','10','400');
-- insert into distance values ('1','11','400');
-- insert into distance values ('1','12','200');
-- insert into distance values ('1','13','400');
-- insert into distance values ('1','14','100');
-- insert into distance values ('2','3','200');
-- insert into distance values ('2','4','300');
-- insert into distance values ('2','5','400');
-- insert into distance values ('2','6','600');
-- insert into distance values ('2','7','100');
-- insert into distance values ('2','8','200');
-- insert into distance values ('2','9','300');
-- insert into distance values ('2','10','800');
-- insert into distance values ('2','11','900');
-- insert into distance values ('2','12','100');
-- insert into distance values ('2','13','100');
-- insert into distance values ('2','14','150');
-- insert into distance values ('3','4','200');
-- insert into distance values ('3','5','250');
-- insert into distance values ('3','6','300');
-- insert into distance values ('3','7','350');
-- insert into distance values ('3','8','400');
-- insert into distance values ('3','9','500');
-- insert into distance values ('3','10','600');
-- insert into distance values ('3','11','700');
-- insert into distance values ('3','12','800');
-- insert into distance values ('3','13','900');
-- insert into distance values ('3','14','100');
-- insert into distance values ('4','5','100');
-- insert into distance values ('4','6','200');
-- insert into distance values ('4','7','300');
-- insert into distance values ('4','8','150');
-- insert into distance values ('4','9','140');
-- insert into distance values ('4','10','400');
-- insert into distance values ('4','11','600');
-- insert into distance values ('4','12','700');
-- insert into distance values ('4','13','800');
-- insert into distance values ('4','14','90');


-- insert into train(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170501','20','20','20','20','20');
-- insert into train(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170502','20','20','20','20','20');
-- insert into train(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170503','20','20','20','20','20');
-- insert into train(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl101','3','4','20170503','20','20','20','20','20');
-- insert into train(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('mi123','1','2','20170503','20','20','20','20','20');


-- insert into train2(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170501','20','20','20','20','20');
-- insert into train2(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170502','20','20','20','20','20');
-- insert into train2(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl123','1','2','20170503','20','20','20','20','20');
-- insert into train2(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('dl101','3','4','20170503','20','20','20','20','20');
-- insert into train2(trainno,src,des,rdate,ac1seats,ac2seats,ac3seats,sleeper1seats,sleeper2seats) values ('mi123','1','2','20170503','20','20','20','20','20');


-- insert into fares (trainno,class,price) values('dl123','ac1seats','300');
-- insert into fares (trainno,class,price) values('dl123','ac2seats','200');
-- insert into fares (trainno,class,price) values('dl123','ac3seats','100');
-- insert into fares (trainno,class,price) values('dl123','sleeper1seats','50');
-- insert into fares (trainno,class,price) values('dl123','sleeper2seats','30');

-- insert into fares (trainno,class,price) values('dl101','ac1seats','300');
-- insert into fares (trainno,class,price) values('dl101','ac2seats','200');
-- insert into fares (trainno,class,price) values('dl101','ac3seats','100');
-- insert into fares (trainno,class,price) values('dl101','sleeper1seats','50');
-- insert into fares (trainno,class,price) values('dl101','sleeper2seats','30');

-- insert into fares (trainno,class,price) values('mi123','ac1seats','300');
-- insert into fares (trainno,class,price) values('mi123','ac2seats','200');
-- insert into fares (trainno,class,price) values('mi123','ac3seats','100');
-- insert into fares (trainno,class,price) values('mi123','sleeper1seats','50');
-- insert into fares (trainno,class,price) values('mi123','sleeper2seats','30');

-- insert into intermediate_stations(trainno,stno) values('dl123','1');
-- insert into intermediate_stations(trainno,stno) values('dl123','2');
-- insert into intermediate_stations(trainno,stno) values('dl123','3');
-- insert into intermediate_stations(trainno,stno) values('dl123','4');

-- insert into intermediate_stations(trainno,stno) values('mi123','1');
-- insert into intermediate_stations(trainno,stno) values('mi123','2');
-- insert into intermediate_stations(trainno,stno) values('mi123','3');
-- insert into intermediate_stations(trainno,stno) values('mi123','4');

-- insert into intermediate_stations(trainno,stno) values('dl101','3');
-- insert into intermediate_stations(trainno,stno) values('dl101','4');
-- insert into intermediate_stations(trainno,stno) values('dl101','5');
-- insert into intermediate_stations(trainno,stno) values('dl101','1');

-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl123','1','080700','080800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl123','3','110700','110800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl123','4','120700','120800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl123','2','130700','130800'); 

-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl101','1','080700','080800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl101','3','110700','110800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl101','4','120700','120800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('dl101','5','130700','130800'); 

-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('mi123','1','080700','080800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('mi123','3','110700','110800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('mi123','4','120700','120800'); 
-- insert into schedule(trainno,stno,arrivaltime,departuretime) values('mi123','2','130700','130800'); 


-- delimiter //
-- create trigger mytrigger3 after delete on seats_waiting
-- FOR EACH ROW
-- begin
	

-- 	update seats_required
-- 	set seats_required.count = customer_1.count-val;
-- 	where seats_required.pnr = pnr;
-- 	-- END IF;
-- END; //
-- delimiter ;




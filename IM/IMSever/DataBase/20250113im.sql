use 20250113im;
create table t_user(
id bigint primary key auto_increment,
name varchar(30) unique not null,
tel varchar(15) unique not null,
passwd varchar(20) not null,
feeling varchar(100),
iconid int
);

create table t_friend(
idA bigint,
idB bigint
);

show global variables;

select *from t_user;
insert into t_friend (idA,idB) values(1,2);
insert into t_friend (idA,idB) values(2,1);

CREATE TABLE offline_msg (
    id INT PRIMARY KEY AUTO_INCREMENT,
    sender_id INT NOT NULL,
    receiver_id INT NOT NULL,
    content VARCHAR(1024),
    send_time DATETIME DEFAULT CURRENT_TIMESTAMP,
    is_delivered TINYINT DEFAULT 0
);
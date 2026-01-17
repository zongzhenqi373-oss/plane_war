#数据库注释使用井号
#sql语句的结尾用;标识
#数据库不区分大小写
#执行sql语句
#闪电:
#1、没有选择sql语句的时候，从当前sql脚本文件的第一行开始执行，执行到文件结尾或者是出错
#2、选中sql语句，就是执行选中的一条或者是多条sql语句
#带光标的闪电:只能执行光标所在行的sql语句




#--------------------------------------------------------------------------------------------------------
##设置默认的库
use 20250113test;

#--------------------------------------------------------------------------------------------------------
##创建表
#语法：create table 表名(列名1 数据类型 建表约束,列名2 数据类型 建表约束,···);
#字符串类型(字符串长度)
#char(15):一个字符占一个字节，固定长度15，如果存储"hello world"，实际存储的是"hello world0000"
#nchar(15):一个字符占两个字节，固定长度15，如果存储"hello world"，实际存储的是"hello world0000"
#varchar(15):一个字符占一个字节，最大长度是15，如果存储"hello world"，实际存储的是"hello world"，但不能超过15
#nvarchar(15):一个字符占两个字节，最大长度占15，如果存储"hello world"，实际存储的是"hello world"

##建表约束
#主键：primary key，一个表中只能有一列主键列，要求数据唯一且不为空
#唯一：unique，要求数据唯一，一个表中可以有多个唯一列
#非空：not null，要求数据不为空
#默认值：default
#自增：auto_increment，(序号，排名)int，bigint等整型可以自增
#外键约束：当前列和其他表中的列有联系

#创建一个表，学号(主键 自增) 姓名(唯一 非空) 性别(枚举值'男'，'女') 年龄(默认18岁)
create table studentinfo(
id int primary key auto_increment,
sname varchar(10) unique not null,
sex enum('男','女'),
age int default 18	
);

#--------------------------------------------------------------------------------------------------------
##修改表：alter table 表名···;
#1、增加列：alter table 表名 add column 列名 数据类型 建表约束;
alter table studentinfo add column school int;

#2、修改列的属性：alter table 表明名 modify 列名 数据类型 建表约束;
alter table studentinfo modify school varchar(15) default '东北大学';

#3、删除列：alter table 表明名 drop 列名
#alter table studentinfo drop school;

#删除表：drop table 表名;
#drop table studentinfo;

#--------------------------------------------------------------------------------------------------------
#插入所有列的数据(值的顺序要和表中列的顺序一致)：insert into 表名 values(值1,值2,···);
#插入部分列的数据：(值的顺序要和前面列的顺序一致)：insert into 表名(列1,列2···) values(值1,值2,···);
insert into studentinfo values(1,'宗振启','男',22,'东北大学');

insert into studentinfo (sname,sex) values('李佳遥','女');
insert into studentinfo (sname,sex,age) values('张三','男',22);
insert into studentinfo (sname,sex,age) values('小红','女',17);
insert into studentinfo (sname,sex,age) values('王五','男',19);
insert into studentinfo (sname,sex,age,school) values('小笨猫','女',19,'哈尔滨理工大学');
insert into studentinfo (sname,sex,age,school) values('宗若彤','女',18,'西安外国语学院');

#--------------------------------------------------------------------------------------------------------
#查询所有列的数据：select *from 表名;
select *from studentinfo;

#查询某一行所有列的数据：select *from 表名 where 条件;
select *from studentinfo where sname = '宗振启';

#查询某一列：select 列名 from 表名;
select sname from studentinfo; 

#查询某一行某一列：select 列名 from 表名 where 条件;
select sname from studentinfo where sname = '宗振启';

#给查询到的列起别名：select 列名1 新的名字,列名2 新的名字,··· from 表名;
select sname 姓名,sex 性别 from studentinfo;

#--------------------------------------------------------------------------------------------------------
#删除某一行：delete from 表名 where 条件;
#删除id为2的同学的信息
delete from studentinfo where id = 2;

#--------------------------------------------------------------------------------------------------------
#更新数据：update 表名 set 列名  = 新的值 where 条件;
#修改id为1的学生年龄为23
update studentinfo set age = 23 where id = 1;
update studentinfo set school = '哈尔滨理工大学' where id = 4;
update studentinfo set school = '哈尔滨理工大学' where id = 6;

#--------------------------------------------------------------------------------------------------------
##条件查询：
#等于、不等于：列名 = 值; 列名 != 值;
#大于、小于、大于等于、小于等于：列名 > 值; 列名 < 值; 列名 >= 值; 列名 <= 值;
#在两者之间：列名 between 值1 and 值2;  
#或者：条件1 or 条件2;
#并且：条件1 and 条件2;
#在范围内：in (范围——可以是另外一条sql语句查询的结果)
#不在范围内：not in(范围)

#查询年龄在20-25之间的学生
select * from studentinfo where age between 20 and 25;

#查询哈尔滨理工大学并且是18岁以上的学生
select * from studentinfo where school = '哈尔滨理工大学' and age > 18;

#查询学号范围在（1，3，5，8）的同学
select * from studentinfo where id in (1,3,5,8);

#--------------------------------------------------------------------------------------------------------
##模糊查询：where 列名 like 模糊表达式
#模糊表达式
# % ：匹配任意0-1个字符
# _ ：匹配任意1个字符

#查找所有宗姓同学的信息
select * from studentinfo where sname like '宗_%';

#--------------------------------------------------------------------------------------------------------
##分页查询：limit a,b(a：查询的起始行数，从0开始；b：查询多少行)
select * from studentinfo limit 1,3;

select * from studentinfo limit 0,6;

#--------------------------------------------------------------------------------------------------------
##聚合函数：
#查总行数：count(列名)
select count(*) from studentinfo;
select count(sname) from studentinfo;
select count(sex) from studentinfo;

#求和：sum(列名)
#查询01号同学的总分
select sum(score) from sc where S = '01';

#求平均值：avg(列名)
#查询01号同学的平均分
select avg(score) from sc where s = '01';
#查询02号课程的平均分
select avg(score) from sc where c = '02';

#求最大值：max(列名)
#查询02号课程的最高分
select max(score) from sc where c = '02';

#求最小值：min(列名)
#查询01号课程的最低分
select min(score) from sc where c = '01';


#--------------------------------------------------------------------------------------------------------
##分组：group by 列名;
#查询所有同学的平均分
select s,avg(score) from sc group by s;

#查询总成绩大于200的学生编号
select s,sum(score) from sc group by s having sum(score) > 200;

#添加条件的时候什么时候用where，什么时候用having
#作为条件的列如果是表中本来就存在的就用where加条件；
#作为条件的列如果不是表中本来就存在的就用having加条件；

#--------------------------------------------------------------------------------------------------------
##排序：order by 列名 排序规则(升序asc/降序desc);(不写规则，默认按照升序排列)
#按照总成绩给班级同学排名
select s,sum(score) from sc group by s order by sum(score);
select s,sum(score) from sc group by s order by sum(score) desc;

#--------------------------------------------------------------------------------------------------------
##去重（对每一行结果）：distinct
select distinct s from sc;
select distinct s,c from sc;


#--------------------------------------------------------------------------------------------------------
drop table sc;
drop table student;
##作业：
create table Student(S varchar(10),Sname nvarchar(10),Sage datetime,Ssex nvarchar(10));
insert into Student values('01' , N'赵雷' , '1990-01-01' , N'男');
insert into Student values('02' , N'钱电' , '1990-12-21' , N'男');
insert into Student values('03' , N'孙风' , '1990-05-20' , N'男');
insert into Student values('04' , N'李云' , '1990-08-06' , N'男');
insert into Student values('05' , N'周梅' , '1991-12-01' , N'女');
insert into Student values('06' , N'吴兰' , '1992-03-01' , N'女');
insert into Student values('07' , N'郑竹' , '1989-07-01' , N'女');
insert into Student values('08' , N'王菊' , '1990-01-20' , N'女');
create table Course(C varchar(10),Cname nvarchar(10),T varchar(10));
insert into Course values('01' , N'语文' , '02');
insert into Course values('02' , N'数学' , '01');
insert into Course values('03' , N'英语' , '03');
create table Teacher(T varchar(10),Tname nvarchar(10));
insert into Teacher values('01' , N'张三');
insert into Teacher values('02' , N'李四');
insert into Teacher values('03' , N'王五');
create table SC(S varchar(10),C varchar(10),score decimal(18,1));
insert into SC values('01' , '01' , 80);
insert into SC values('01' , '02' , 90);
insert into SC values('01' , '03' , 99);
insert into SC values('02' , '01' , 70);
insert into SC values('02' , '02' , 60);
insert into SC values('02' , '03' , 80);
insert into SC values('03' , '01' , 80);
insert into SC values('03' , '02' , 80);
insert into SC values('03' , '03' , 80);
insert into SC values('04' , '01' , 50);
insert into SC values('04' , '02' , 30);
insert into SC values('04' , '03' , 20);
insert into SC values('05' , '01' , 76);
insert into SC values('05' , '02' , 87);
insert into SC values('06' , '01' , 31);
insert into SC values('06' , '03' , 34);
insert into SC values('07' , '02' , 89);
insert into SC values('07' , '03' , 98);
insert into SC values('09' , '03' , 98);

#练习：
#1、查询每门课程被选修的学生数
select c,count(s) from sc group by c;

#2、检索至少选修两门课程的学生学号
select s,count(c) from sc group by s having count(c) >= 2;

#3、求这些学号对应的个人信息
select * from student where s in(select s from sc group by s having count(c) >= 2);

#4、查询选修了全部课程的学生信息
select * from student where s in(select s from sc group by s having count(c) = (select count(c) from course));

#5、查询没有学全所有课程的同学的信息
select * from student where s not in(select s from sc group by s having count(c) = (select count(c) from course));

#6、查询学过"张三"老师授课的同学的信息
select * from student where s in(select s from sc where c in (select c from course where t = (select t from teacher where tname = '张三')));

#7、查询没学过"张三"老师授课的同学的信息
select * from student where s not in(select s from sc where c in (select c from course where t = (select t from teacher where tname = '张三')));

#8、查询每个同学01课程的成绩，包括个人信息
select s.*,s1.score 01score from Student s, SC s1 where s.s = s1.s and s1.c = '01';
select * ,(select score from sc where c = '01' and sc.s = student.s) 01score from student;

#9、查询01课程分数 > 02课程分数 的个人信息
select s.*,s1.score 01score ,s2.score 02score from Student s, SC s1, SC s2 where s.s = s1.s and s.s = s2.s and s1.c ='01' and s2.c = '02' and s1.score > s2.score;
select * from student having (select score from sc where c = '01' and sc.s = student.s) > (select score from sc where c = '02' and sc.s = student.s);

#10、查询同时存在"01"课程和"02"课程的学生信息
select * from student having (select score from sc where c = '01' and sc.s = student.s) is not null and (select score from sc where c = '02' and sc.s = student.s) is not null;

##
#内联：select 列名 from 表1 inner join 表2 on 连接条件;
select * from student inner join sc on sc.S = student.S;

#左联：select 列名 from 表1 left join 表2 on 连接条件;
select * from student left join sc on sc.S = student.S;

#右联：select 列名 from 表1 right join 表2 on 连接条件;
select * from student right join sc on sc.S = student.S;

#笛卡尔积：select 列名 from 表1 , 表2 where 连接条件;
select * from student , sc where sc.S = student.S;

#内联：取两个表的交集，不会出现空数据的问题
#左联：以左边表为基准，从右边表中匹配行，匹配不到就显示空
#右联：以右边表为基准，从左边表中匹配行，匹配不到就显示空
#笛卡尔积：查询结果和内联一致，但是采用排列组合的方式，查询效率低，不推荐使用

#练习：
#1、查询成绩高于60分的学生信息
select distinct student.* from student inner join sc on sc.S = student.S where score > 60 ;

#2、查询每个学生的总成绩以及学生信息
#select s,sum(score) totalsc from sc group by s;
select student.*,sum(sc.score) total_score from student left join sc on sc.S = student.S group by student.S,student.Sage,student.Sname,student.Ssex;

#3、查询总成绩 > 200的学生信息
select student.* from student left join sc on sc.S = student.S group by student.S,student.Sage,student.Sname,student.Ssex having sum(sc.score) > 200;

#4、查询总成绩最低的学生信息
select student.*,sum(sc.score) total_score from student inner join sc on sc.S = student.S group by student.S,student.Sage,student.Sname,student.Ssex order by sum(sc.score) asc limit 0,1 ;

#5、查询学过"张三"老师授课的同学的信息
select student.* from student inner join sc inner join course inner join teacher on sc.s = student.s and sc.C = course.C and course.T = teacher.T where teacher.Tname = '张三';

#6、查询平均成绩大于等于60分的同学的学生编号和学生姓名和平均成绩。
select student.S,student.Sname,avg(sc.score) avg_score from student inner join sc on sc.S = student.S group by student.S,student.Sage,student.Sname,student.Ssex having avg_score >= 60;

#7、查询每门课程被选修的学生数-- 带课程名字。
select sc.C,course.Cname,count(sc.C) sum_course from sc inner join course on sc.C = course.C group by course.C,course.Cname;

#8、查询每门课程被选修的学生数，排序按照选修的学生人数降序排序, 如果人数相等按照课程号升序排列。主排序规则, 次排序规则
select sc.C,course.Cname,count(sc.C) sum_course from sc inner join course on sc.C = course.C group by course.C,course.Cname order by sum_course desc , sc.C asc;

#9、查询同时存在"01"课程和"02"课程的学生的学生信息。
select student.* from student inner join sc on student.S = sc.S where sc.C in ('01','02') group by student.S,student.Sage,student.Sname,student.Ssex having count(*) = 2;

#视图：view，把select语句的查询结果保存起来

#创建视图语法：create view 视图名字 as (select 语句)
#使用视图：当作表使用，但是只能查询
#删除视图：drop view 视图名
select distinct student.* from student inner join sc on sc.S = student.S;
create view myview as(select distinct student.*, C,score from student inner join sc on sc.S = student.S);

select * from myview;
drop view myview;

#视图的优缺点：
#优点：sql语句在网络中传输，使用视图节省流量更安全
#缺点：效率没有改变，还是执行原来的sql语句


#自定义函数
#创建语法：
#delimiter //(##)        #声明//(##)作为sql语句的结束标志
#create function 函数名(参数名 数据类型,参数名，数据类型,...)
#returns 返回值类型
#begin
#函数体语句;
#函数体语句;
#函数体语句;
#end  //
#delimiter ;    #重新声明;为sql语句的结束标志


#调用函数：select 函数名(参数列表)
#删除函数：（直接删除，如果函数不存在会报错，停止向下运行）：drop function 函数名;
#判断函数是否存在再删除(只会有警告，会继续向下运行)：drop function if exists 函数名;
#例子：实现一个加法函数
drop function if exists myadd;
delimiter //
create function myadd(a int,b int)
returns int
DETERMINISTIC 
NO SQL
begin
	declare c int default 0;
	set c = a + b + 200;
	return c;
end //
delimiter ;

select myadd(2,5);


#变量
#局部变量：

#会话变量(生命周期是整个会话):以@变量名;
set @x = 10;
select @x;
#在别的会话中或者关闭后再打开的会话，变量都会不再有值，必须重新声明和赋值

#系统变量(全局变量，生命周期是整个操作系统，自己不能定义，只能查看和修改)：以@@变量名;
#查看所有的系统变量
show global variables;
#查看某个系统变量:select @@系统变量的值
select @@admin_port;



#判断
#if判断语法
#if (表达式1) then 执行语句1;执行语句2;执行语句3;
#elseif (表达式2) then 执行语句1;执行语句2;执行语句3;
#else 执行语句1;执行语句2;执行语句3;
#end if;
#例子：判断是正数，负数还是0
drop function if exists myfunction;
delimiter //
create function myfunction(a int)
returns varchar(4)
DETERMINISTIC 
NO SQL
begin 
	declare res varchar(4) default '';
	if(a > 0) then set res = '正数';
    elseif(a = 0) then set res = '零';
    else set res = '负数';
    end if;
	return res;
end //
delimiter ;
select myfunction(-10);

#case 判断语法
#语法1：
#case 变量 when 值1 then 执行语句1;执行语句2;
#		   when 值2 then 执行语句1;执行语句2;
#		   when 值3 then 执行语句1;执行语句2;
#end case;
#

#语法2：
#case when (表达式1) then 执行语句1;执行语句2;
#	  when (表达式2) then 执行语句1;执行语句2;
#	  when (表达式3) then 执行语句1;执行语句2;
#end case;
#例子：判断是正数，负数还是0
drop function if exists myfunction;
delimiter //
create function myfunction(a int)
returns varchar(4)
DETERMINISTIC 
NO SQL
begin 
	declare res varchar(4) default '';
	case when(a > 0) then set res = '正数';
         when(a = 0) then set res = '零';
         when(a < 0) then set res = '负数';
	end case;
    return res;
end //
delimiter ;
select myfunction(-10);


#while 循环







#其他循环
#SQL中没有for循环，但是有loop和reapt

# 例子：实现青蛙爬井的函数，白天向上爬5米，晚上向下掉4米，问多少天能从井中出来。
# 返回值nDay int，参数是井的高度high int。
# 需要使用循环和判断
drop function if exists drag_pj;
delimiter //
create function drag_pj(hight int)
returns int 
DETERMINISTIC 
NO SQL
begin
	declare nDay int default 0;
    declare nhight int default 0;
	# 进循环，白天
	qwpj: loop
		# 天数+1，米数+5
		set nDay = nDay+1;
        set nhight = nhight+5;
		# 判断米数是不是超过了井的高度
		if (nhight < hight) then set nhight = nhight - 4; #晚上，米数-4
		else leave qwpj;
        end if;
	end loop qwpj;
    return nDay;
end // 
delimiter //
select drag_pj(10);


#存储过程：procedure，大型数据库中一系列sql语句的集合，编译之后保存在数据库中，提升运行效率

#创建语法：
#delimiter // 
#create procedure 存储过程(参数名 数据类型,参数名，数据类型,...)
#begin
# sql集合;
# sql集合;
#end //
#delimiter ;
#注意：存储过程没有返回值，参数类型有in|out|inout，可以通过out或者inout类型的参数返回数据

#执行存储过程：call procedure 存储过程名(参数列表);
#删除存储过程：drop procedure if exists 存储过程名;



#例子：分页存储过程，输入参数是当前是第几页(page int)，每页显示多少行(count int)。
#固定查询student表，要进行参数校验
#校验规则：
#page小于1的时候，显示第一页数据
#page超过最大页数(计算最大页数，不能整除的时候，小数取整，数据库默认采用四舍五入的原则)，显示最后一页的数据

drop procedure if exists page_student;
delimiter //

create procedure page_student(page int, count int)
begin
    declare total_rows int default 0;      -- 学生总行数
    declare max_page int default 0;        -- 最大页数
    declare start_row int default 0;       -- 查询起始行

    -- 获取总行数
    select count(*) into total_rows from student;

    -- 防止除零错误
    if count <= 0 then
        set count = 3;  -- 默认每页3行
    end if;

    -- 计算最大页数（ceil：向上取整）
    set max_page = ceil(total_rows / count);

    -- 校验 page 参数
    if page < 1 then
        set page = 1;
    elseif page > max_page then
        set page = max_page;
    end if;

    -- 计算偏移量（limit 的起点）
    set start_row = (page - 1) * count;

    -- 输出分页数据
    select student.*,page as current_page,max_page as total_page,total_rows as total_rows from student limit start_row, count;
end;
//
DELIMITER ;
call page_student(3,3);

#函数与存储过程的区别











#触发器：trigger，是一种特殊的存储过程，当指定事件发生的时候，系统自动调用
#语法：
#delimiter //
#create trigger 触发器名字before/after 操作名        -- 执行xxx操作之前或者之后
#on 表名                                           -- 对某个表进行操作
#for each row                                     -- 影响每一行
#begin
#触发要执行的语句;                                   -- 触发要执行的事情
#end //
#delimiter ;

#删除触发器：drop trigger if exists 触发器名字;

#例子：当删除student表的时候，自动删除sc表中的该同学对应的信息
drop trigger if exists delete_student;
delimiter //
create trigger delete_student
after delete
on student
for each row
begin
	#删除这个学生对应的成绩
	delete from sc where s = old.s;
    #new表：新增加的数据，修改之后的数据
    #old表：修改之前的数据，删除之前的数据
end //
delimiter ;

#student中删除一个学生
set sql_safe_updates = 0;
delete from student where sname = '赵雷';
set sql_safe_updates = 1;


#例子：当student中新增加一个学生，给这个学生自动选择01和02课程，分数为null
drop trigger if exists add_student;
delimiter //
create trigger add_student
after insert
on student
for each row
begin
	#给这个学生自动选择01和02课程
	insert into sc(s,c,score)values(new.s,'01',null);
    insert into sc(s,c,score)values(new.s,'02',null);
end //
delimiter ;

#student中新增加一个学生
insert into student(s,sname,ssex)values('12','宗振启','男');


#例子：当修改student表中学生学号，同时修改sc表中这个学生的学号
drop trigger if exists update_student;
delimiter //
create trigger update_student
after update
on student
for each row
begin
	#修改sc表中这个学生的学号
	update sc set s = new.s where s = old.s; 
end //
delimiter ;

#修改studen表中学生的学号
set sql_safe_updates = 0;
update student set s = '10' where Sname = '宗振启';
set sql_safe_updates = 1;

#事务：transaction,为了实现一组sql语句要么都执行成功，要么都执行失败
#创建一个银行的表
create table bank(
name varchar(10),
money double,
check(money >= 0)              -- 在mysql中check不生效
);

insert into bank values('宗振启',1000);
insert into bank values('李佳遥',50);

select * from bank;

#宗振启给李佳遥转了520
set sql_safe_updates = 0;
update bank set money = money - 520 where name = '宗振启';
update bank set money = money + 520 where name = '李佳遥';
set sql_safe_updates = 1;

#事务特性：
#原子性：把事务当做一个整体执行，要么都成功，要么都失败
#一致性：数据库的完整性约束不能被破坏
#隔离性：多个并行执行的事务，相互之间是隔离的（事务有不同的隔离级别）
#持久性：事务中对数据的修改提交以后永久的保存在数据库中


#使用方法
#开启事务：start transaction;
#一组sql语句;
#有两个选择（单选）：rollback/commit
#rollback：回滚，数据恢复到开启事务之前的状态
#commit：提交，对数据的修改保存到数据库中，此时其他人才能看到修改后的结果

start transaction;
select * from bank;

#宗振启给李佳遥借了520
set sql_safe_updates = 0;
update bank set money = money + 520 where name = '宗振启';
update bank set money = money + 520 where name = '李佳遥';
set sql_safe_updates = 1;

rollback;
commit;
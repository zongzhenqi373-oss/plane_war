#include "Kernel.h"
#include"mediator/TCPServermediator.h"

Kernel* Kernel::m_pKernel = nullptr;
Kernel::Kernel()
{
	setFunArr();
	m_pKernel = this;
	m_pMediator = new TCPServermediator;

}
Kernel::~Kernel()
{
	if (m_pMediator)
	{
		m_pMediator->closeNet();
		delete m_pMediator;
		m_pMediator = nullptr;
	}

}

//初始化函数指针数组
void Kernel::setFunArr()
{
	cout << __func__ << endl;
	//初始化数组
	memset(m_dealFunArr, 0, sizeof(m_dealFunArr));

	//把函数地址保存到数组中
	m_dealFunArr[DEF_PROT_REGISTER_RQ       - DEF_BASE] = &Kernel::DealRegisterRq;
	m_dealFunArr[DEF_PROT_LOGIN_RQ		    - DEF_BASE] = &Kernel::DealLoginRq;
	m_dealFunArr[DEF_PROT_FRIEND_OFFLINE	- DEF_BASE] = &Kernel::DealOfflineRq;
	m_dealFunArr[DEF_PROT_CHAT_INFO_RQ      - DEF_BASE] = &Kernel::DealChatRq;
	m_dealFunArr[DEF_PROT_ADD_FRIEND_RQ		- DEF_BASE] = &Kernel::DealAddFriendRq;
	m_dealFunArr[DEF_PROT_ADD_FRIEND_RS		- DEF_BASE] = &Kernel::DealAddFriendRs;
}

//打开服务器
bool Kernel::startServer()
{
	//打开网络
	if (!m_pMediator->openNet())
	{
		cout << "打开服务器失败！" << endl;
		return false;
	}
	//连接数据库
	char ip[] = "127.0.0.1";
	char user[] = "root";
	char pass[] = "zongzhenqi373";
	char db[] = "20250113im";
	if (!m_mysql.ConnectMySql(ip, user, pass, db))
	{
		cout << "连接数据库失败！" << endl;
		return false;
	}

	return true;
}

//关闭服务器
void Kernel::closeServer()
{
	//关闭网络
	m_pMediator->closeNet();
	//断开与数据库的连接
	m_mysql.DisConnect();

}

//处理和分发所有收到的数据
void Kernel::DealData(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	//取出协议类型
	protType type = *(protType*)data;

	//计算数组下表
	int index = type - DEF_BASE;

	//判断数组下标是否在有效范围内
	if (index >= 0 && index < DEF_PROT_COUNT)
	{
		//根据数组下标取出函数地址
		DEAL_FUN pFun = m_dealFunArr[index];
		//判断函数指针是否有效
		if (pFun)
		{
			(this->*pFun)(data, len, from);   //函数指针是一个变量，需要把this显式写出来，不然不知道作用域
		}
		else  //指针为空：1、结构体的type值写错了；2、发过来的结构体错了
		{
			cout << "type2:" << type << endl;
		}
	}
	else   //越界了1、offset没有清零2、结构体声明的时候prottype没有放在第一个定义3、客户端发送的错误4、测试代码没删
	{
		cout << "type1:" << type << endl;
	}
}

//处理注册请求的函数
void Kernel::DealRegisterRq(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	//1、拆包
	PROT_REGISTER_RQ* rq = (PROT_REGISTER_RQ*)data;

	//2、根据昵称从数据库中查询昵称
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql,"select name from t_user where name = '%s';",rq->nick);
	if (!m_mysql.SelectMySql(sql,1,listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;
	}

	PROT_REGISTER_RS rs;
	//3、判断昵称查询结果是否为空
	if (listRes.size() == 0)
	{
		//如果为空说明昵称未被注册
		//4、根据电话号码从数据库中查询
		sprintf_s(sql, "select tel from t_user where tel = '%s';", rq->tel);
		if (!m_mysql.SelectMySql(sql, 1, listRes))
		{
			cout << "查询数据库失败！" << sql << endl;
			return;
		}
		//5、判断电话号码查询结果是否为空
		if (listRes.size() == 0)
		{
			//如果为空，说明电话号码没被注册
			//6、把用户注册的信息存入数据库中
			sprintf_s(sql ,"insert into t_user (name,tel,passwd,feeling,iconid) values ('%s','%s','%s','努力实现财富自由',3);"
				      ,rq->nick,rq->tel,rq->pass);
			if (!m_mysql.UpdateMySql(sql))
			{
				cout << "保存信息失败！" << sql << endl;
				return;
			}
			rs.result = REGISTER_SUCC;
		}
		else
		{
			//如果不为空，那么说明电话号码被注册过，注册失败
			rs.result = REGISTER_TEL_EXIT;
		}
	}
	else
	{
		//如果不为空，说明昵称被注册过，注册失败
		rs.result = REGISTER_NICK_EXIT;
	}

	//4、不管注册结果成功还是失败，都要给客户端返回注册结果
	m_pMediator->sendData((char*)&rs, sizeof(rs), from);
}

//处理登录请求的函数
void Kernel::DealLoginRq(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	PROT_LOGIN_RQ* rq = (PROT_LOGIN_RQ*)data;

	//根据电话号码查询密码
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql, "select passwd,id from t_user where tel = '%s';", rq->tel);
	if (!m_mysql.SelectMySql(sql,2,listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;	
	}

	PROT_LOGIN_RS rs;
	//判断查询密码是否为空
	if (listRes.size() == 0)
	{
		//如果为空，说明电话号码没有注册过，登陆失败
		rs.result = LOGIN_NOTEXIT;
		cout << "登录失败！" << endl;
	}
	else
	{
		//如果不为空，那就从listRes中取出密码
		string passLine = listRes.front();
		listRes.pop_front();   //从list中删除取走的数据
		int id = stoi(listRes.front());
		listRes.pop_front();   //从list中删除取走的数据

		//比较取出的密码和登录输入的密码是否相等
		if (passLine == string(rq->pass))
		{
			//如果相等，那么登录成功
			rs.result = LOGIN_SUCCESS;
			rs.userid = id;

			//保存当前用户的id和socket
			m_mapIdtoSocket[id] = from;

			m_pMediator->sendData((char*)&rs, sizeof(rs), from);

			cout << "lllllllllll" << endl;

			//根据id查询当前用户以及好友的信息
			getUserInfoAndFriendInfo(id);

			// 发送离线消息（关键）
			sendOfflinemsg(id);

			return;
		}
		else
		{
			//如果不相等，那么登录失败，密码错误
			rs.result = LOGIN_PASSERROR;
		}
	}
	m_pMediator->sendData((char*)&rs, sizeof(rs), from);
}

//根据id查询当前用户以及好友的信息
void Kernel::getUserInfoAndFriendInfo(int id)
{
	cout << __func__ << endl;
	//根据自己的id查询自己的信息
	PROT_FRIEND_INFO Myinfo = {};
	getInfoById(id, &Myinfo);

	//把自己的信息发送给客户端
	if (m_mapIdtoSocket.count(id) > 0)
	{
		m_pMediator->sendData((char*)&Myinfo, sizeof(Myinfo), m_mapIdtoSocket[id]);
	}
	else
	{
		cout<< "ID:" << id << endl;
	}
	

	//根据自己的id查询好友的id
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql, "select idB from t_friend where idA = '%d';", id);
	if (!m_mysql.SelectMySql(sql, 1, listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;
	}

	//遍历好友列表
	int friendid = 0;
	PROT_FRIEND_INFO Friendinfo = {};
	while (listRes.size() > 0)
	{
		//根据好友的id查询好友的信息
		friendid = stoi(listRes.front());
		listRes.pop_front();   //从list中删除取走的数据
		getInfoById(friendid, &Friendinfo);

		//把好友的信息发送给客户端
		if (m_mapIdtoSocket.count(id) > 0)
		{
			m_pMediator->sendData((char*)&Friendinfo, sizeof(Friendinfo), m_mapIdtoSocket[id]);
		}
		else
		{
			cout << "ID:" << id << endl;
		}
		//查看朋友在不在线
		if (m_mapIdtoSocket.count(friendid) > 0)
		{
			//如果在线，那么给好友发送自己的信息
			m_pMediator->sendData((char*)&Myinfo, sizeof(Myinfo), m_mapIdtoSocket[friendid]);
		}
	}
	
}

//根据id查询用户信息
void Kernel::getInfoById(int id, PROT_FRIEND_INFO* info)
{
	cout << __func__ << endl;
	info->userid = id;
	if (m_mapIdtoSocket.count(id) > 0)
	{
		//在线
		info->status = STATUS_ONLINE;
	}
	else
	{
		//不在线
		info->status = STATUS_OFFLINE;
	}
	//根据id查询用户名字，签名，头像id
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql, "select name,feeling,iconid from t_user where id = '%d';", id);
	if (!m_mysql.SelectMySql(sql, 3, listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;
	}

	if (listRes.size() == 3)
	{
		//从list中取出昵称
		string nick = listRes.front();
		strcpy_s(info->nick, sizeof(info->nick), nick.c_str());
		listRes.pop_front();   //从list中删除取走的数据

		//从list中取出签名
		string feeling = listRes.front();
		strcpy_s(info->feeling, sizeof(info->feeling), feeling.c_str());
		listRes.pop_front();   //从list中删除取走的数据

		//从list中取出头像id
		info->iconid = stoi(listRes.front());
		listRes.pop_front();   //从list中删除取走的数据
	}
	else
	{
		cout << "sql；" << sql << endl;
	}
}

//离线消息发送
void Kernel::sendOfflinemsg(int id) {
	cout << __func__ << endl;

	char sql[512] = "";
	sprintf_s(sql,
		"select id,sender_id,content from offline_msg where receiver_id=%d and is_delivered=0 order by send_time ASC;",
		id);

	list<string> lst;
	if (!m_mysql.SelectMySql(sql, 3, lst)) {
		cout << "查询数据库失败！" << sql << endl;
		return;
	}

	PROT_CHAT_INFO_RQ rq;
	if (lst.size()==0) {
		cout << "消息列表没有要发送的数据！" << endl;
	}
	else
	{
		auto it = lst.begin();
		while (it != lst.end())
		{
			int msgId = atoi(it->c_str()); it++;
			int senderId = atoi(it->c_str()); it++;
			string content = *it;
			it++;

			rq.myid = senderId;
			rq.friid = id;
			strcpy_s(rq.msg, content.c_str());

			// 发送给当前已登录用户
			m_pMediator->sendData(
				(char*)&rq,
				sizeof(rq),
				m_mapIdtoSocket[id]
			);


			// 标记该消息已投递
			char updateSql[128] = "";
			sprintf_s(updateSql,
				"update offline_msg set is_delivered=1 where id=%d;",
				msgId);
			m_mysql.UpdateMySql(updateSql);
		}
	}
}

//处理下线请求
void Kernel::DealOfflineRq(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	PROT_FRIEND_OFFLINE* offlineRq = (PROT_FRIEND_OFFLINE*)data;
	//1、根据id查找下线用户的好友id列表
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql, "select idB from t_friend where idA = '%d';", offlineRq->offlineid);
	if (!m_mysql.SelectMySql(sql, 1, listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;
	}
	//2、遍历好友id列表
	int friendid = 0;
	while (listRes.size() > 0)
	{
		//3、取出好友的id
		friendid = stoi(listRes.front());
		//4、从列表中删除已经取出的好友id
		listRes.pop_front();
		//5、判断好友是否在线
		if (m_mapIdtoSocket.count(friendid) > 0)
		{
			//6、如果在线，就给在线好友发送下线请求
			m_pMediator->sendData(data,len,m_mapIdtoSocket[friendid]);
		}

	}
	//7、取出map中的套接字，关闭套接字，并且把无效节点删除
	if (m_mapIdtoSocket[offlineRq->offlineid] > 0)
	{
		closesocket(m_mapIdtoSocket[offlineRq->offlineid]);
		m_mapIdtoSocket.erase(offlineRq->offlineid);
	}
}

//处理聊天请求
void Kernel::DealChatRq(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	PROT_CHAT_INFO_RQ* rq = (PROT_CHAT_INFO_RQ*)data;
	//判断好友是否在线
	if (m_mapIdtoSocket.count(rq->friid) > 0)
	{
		//如果在线，那么把聊天请求转发给好友
		m_pMediator->sendData(data, len, m_mapIdtoSocket[rq->friid]);
	}
	else
	{
		//如果不在线，那么回复一个不在线状态给客户端并将消息保存到消息列表数据库
		char sql[1024] = "";
		sprintf_s(sql,
			"insert into offline_msg (sender_id, receiver_id, content) values(%d, %d, '%s');",
			rq->myid,
			rq->friid,
			rq->msg);

		m_mysql.UpdateMySql(sql);
		cout << "离线消息已保存" << endl;

		PROT_CHAT_INFO_RS rs(rq->friid, 0, CHAT_RESULT_FAIL);
		m_pMediator->sendData((char*)&rs,sizeof(rs),from);
	}
}

//处理添加好友请求
void Kernel::DealAddFriendRq(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	PROT_ADD_FRIEND_RQ* rq = (PROT_ADD_FRIEND_RQ*)data;
	//根据好友昵称查询好友id
	list<string> listRes;
	char sql[1024] = "";
	sprintf_s(sql, "select id from t_user where name = '%s';", rq->frinick);
	if (!m_mysql.SelectMySql(sql, 1, listRes))
	{
		cout << "查询数据库失败！" << sql << endl;
		return;
	}
	//判断查询结果是否为空
	if (listRes.size() == 0)
	{
		//如果为空，添加好友失败，说明好友不存在，回复一个好友不存在的信息给客户端
		PROT_ADD_FRIEND_RS rs;
		rs.result = ADD_FRIEND_NOTEXIT;
		strcpy_s(rs.mynick ,sizeof(rs.mynick), rq->frinick); 
		m_pMediator->sendData((char*)&rs, sizeof(rs), from);
	}
	else
	{
		//如果不为空没，那么用户存在，判断好友当前是否在线
		int friendid = 0;
		friendid = stoi(listRes.front());
		listRes.pop_front();
		if (m_mapIdtoSocket[friendid] > 0)
		{
			//如果在线，将添加好友的请求转发给用户
			m_pMediator->sendData(data, len, m_mapIdtoSocket[friendid]);
		}
		else
		{
			//如果不在线，那么回复一个好友不在线的信息给客户端，好友添加失败
			PROT_ADD_FRIEND_RS rs;
			rs.result = ADD_FRIEND_OFFLINE;
			strcpy_s(rs.mynick, sizeof(rs.mynick), rq->frinick);
			m_pMediator->sendData((char*)&rs, sizeof(rs), from);
		}

	}
}

//处理添加好友回复
void Kernel::DealAddFriendRs(char* data, int len, unsigned long from)
{
	cout << __func__ << endl;
	PROT_ADD_FRIEND_RS* rs = (PROT_ADD_FRIEND_RS*)data;

	//如果好友同意添加
	if (rs->result == ADD_FRIEND_AGREE)
	{
		//将双方的好友信息写入到数据库中
		char sql[1024] = "";
		sprintf_s(sql, "insert into t_friend values(%d ,%d) ;", rs->destid , rs->myid);
		if (!m_mysql.UpdateMySql(sql))
		{
			cout << "插入数据库失败！" << sql << endl;
			return;
		}

		sprintf_s(sql, "insert into t_friend values(%d ,%d) ;", rs->myid , rs->destid);
		if (!m_mysql.UpdateMySql(sql))
		{
			cout << "插入数据库失败！" << sql << endl;
			return;
		}

		//更新双方好友列表
		getUserInfoAndFriendInfo(rs->destid);

	}
	//无论结果如何，都把回复的数据传给发起好友申请的客户端
	if (m_mapIdtoSocket.count(rs->destid) > 0)
	{
		m_pMediator->sendData(data, len, m_mapIdtoSocket[rs->destid]);
	}

}
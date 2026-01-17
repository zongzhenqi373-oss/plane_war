#pragma once
#include<iostream>
#include<map>
#include"mediator/INetmediator.h"
#include"net/def.h"
#include"MySQL/CMySql.h"


using namespace std;

class Kernel
{
public:
	static Kernel* m_pKernel;
	Kernel();
	~Kernel();

	//初始化函数指针数组
	void setFunArr();

	//打开服务器
	bool startServer();
	//关闭服务器
	void closeServer();

	//处理和分发所有收到的数据
	void DealData(char* data, int len, unsigned long from);

	//处理注册请求的函数
	void DealRegisterRq(char* data, int len, unsigned long from);

	//处理登录请求的函数
	void DealLoginRq(char* data, int len, unsigned long from);

	//根据id查询当前用户以及好友的信息
	void getUserInfoAndFriendInfo(int id);

	//根据id查询用户信息
	void getInfoById(int id, PROT_FRIEND_INFO* info);

	//离线消息发送
	void sendOfflinemsg(int id);

	//处理下线请求
	void DealOfflineRq(char* data, int len, unsigned long from);

	//处理聊天请求
	void DealChatRq(char* data, int len, unsigned long from);

	//处理添加好友请求
	void DealAddFriendRq(char* data, int len, unsigned long from);

	//处理添加好友回复
	void DealAddFriendRs(char* data, int len, unsigned long from);


private:
	INetmediator* m_pMediator;
	//定义函数指针
	using DEAL_FUN = void(Kernel::*)(char*, int, unsigned long);
	//函数指针数组
	DEAL_FUN m_dealFunArr[DEF_PROT_COUNT];

	//数据库对象
	CMySql m_mysql;
	map<int, unsigned long> m_mapIdtoSocket;


};


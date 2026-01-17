#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>

#pragma comment(lib,"Ws2_32.lib")

using namespace std;


int main()
{
	//1.加载库
	WORD version = MAKEWORD(2, 2);
	WSADATA data = {};
	int err = WSAStartup(version, &data);
	if (err != 0)
	{
		cout << "WSAStartup failed with error: " << err << endl;
		return 1;
	}

	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2)
	{
		cout << "WSAStartup success!" << endl;
	}
	else
	{
		cout << "WSAStartup error" << endl;
		WSACleanup();
		return 1;
	}

	//2.创建套接字
	SOCKET s = socket(AF_INET/*IP地址类型，用的是IPV4*/, SOCK_DGRAM/*UDP协议，报文协议，套接字类型*/, IPPROTO_UDP/*传输使用的协议，UDP协议*/);
	if (INVALID_SOCKET == s)
	{
		//错误码在哪查找原因：工具->错误查找
		cout << "socket error:" << WSAGetLastError()/*打印错误码*/ << endl;
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "socket success!" << endl;
	}

	//3.设置服务端的地址和端口
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(12345);
	//serverAddr.sin_addr.S_un.S_addr = inet_addr("172.29.65.74");   //发送的时候必须指定IP地址

	//发直接广播
	//serverAddr.sin_addr.S_un.S_addr = inet_addr("172.29.255.255");

	//发有限广播
	//申请广播权限
	BOOL val = true;
	setsockopt(s,SOL_SOCKET,SO_BROADCAST,(char*)&val,sizeof(val));   //申请广播权限
	serverAddr.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");


	int nRecvNum = 0;
	int nSendNum = 0;
	char SendBuf[1024] = "";
	char RecvBuf[1024] = "";

	while (true)
	{
		cin >> SendBuf;
		//4.发送数据
		nSendNum = sendto(s,SendBuf,strlen(SendBuf)+1,0,(sockaddr*)&serverAddr,sizeof(serverAddr));
		if (nSendNum == SOCKET_ERROR)
		{
			cout << "sendto error:" << WSAGetLastError()/*打印错误码*/ << endl;
			break;
		}

		////5.接收数据
		//nRecvNum = recvfrom(s, RecvBuf, sizeof(RecvBuf), 0, nullptr, nullptr);
		//if (nRecvNum>0)
		//{
		//	cout << "接收到服务端消息：" << RecvBuf << endl;
		//}
		//else
		//{
		//	cout << "recvfrom error:" << WSAGetLastError()/*打印错误码*/ << endl;
		//	break;
		//}
		
	}

	//6.关闭套接字
	closesocket(s);

	//7.卸载库
	WSACleanup();



	return 0;
}
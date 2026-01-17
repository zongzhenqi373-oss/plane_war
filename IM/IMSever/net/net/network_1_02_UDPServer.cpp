#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

//导入依赖库


int main()
{
	//1.加载库
	WORD version = MAKEWORD(2, 2);
	WSADATA data = {};
	int err = WSAStartup(version,&data/*输出参数，函数给你的变量赋值*/);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		cout << "WSAStartup failed with error: " << err << endl;
		return 1;
	}

	//加载库成功，判断库的版本号是否正确
	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2)
	{
		cout << "WSAStartup success!" << endl;
	}
	else   //虽然加载库成功了，但是版本号不正确
	{
		cout << "WSAStartup error!" << endl;

		//卸载库
		WSACleanup();
		return 1;
	}


	//2.创建套接字（使用IPV4地址，UDP协议）
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
		cout << "socket success!"  << endl;
	}

	//3.绑定ip和端口
	sockaddr_in saddr;
	saddr.sin_family = AF_INET;  /*IP地址类型，用的是IPV4*/
	saddr.sin_port = htons(12345);   //转换成网络字节序
	saddr.sin_addr.S_un.S_addr = ADDR_ANY;   //绑定所有网卡

	err = bind(s,(sockaddr*)&saddr,sizeof(saddr));
	if (err == SOCKET_ERROR)
	{
		cout << "bind error:" << WSAGetLastError()/*打印错误码*/ << endl;
		closesocket(s);
		WSACleanup();
		return 1;
	}
	else
	{
		cout << "bind success!" << endl;
	}

	int nRecvNum = 0;
	int nSendNum = 0;
	char recvBuf[1024] = "";
	char sendBuf[1024] = "";
	sockaddr_in addrFrom = {};
	int size = sizeof(addrFrom);

	//获取发送缓冲区和接收缓冲区的大小   :   64k  =  64*1024
	int recvSize = 0;
	int sendSize = 0;
	int optLen = sizeof(recvSize);
	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&recvSize, &optLen);
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&sendSize, &optLen);
	cout << "recvSize: " << recvSize << "   " << "sendSize: " << sendSize << endl;

	/*
	int      //一般用来表示成功或者失败，0是成功，错误码是失败
	WSAAPI   //__stdcall:一种函数调用约定
	getsockopt(
		SOCKET s,        // 套接字描述符
		int level,       // 选项所在的协议层
		int optname,     // 选项名
		char *optval,    // 输出缓冲区，存放获取到的选项值
		int *optlen      // 输入：缓冲区大小；输出：实际返回的长度
		                 //输入：*optlen 表示 optval 缓冲区大小（字节数）。输出：函数填充后，*optlen 会被更新为实际返回的选项长度。
	);
	*/

	//阻塞和非阻塞
	//阻塞：如果等待的事情没有发生，就一直在这等着，不继续向下运行（特点：1.等待的事情发生的时候，第一时间执行；2.等待时间不占用cpu）
	//非阻塞：如果等待的事情没有发生，可以继续向下运行代码（特点：1.等待的事情发生的时候，不能第一时间执行；2.等待的过程占用cpu，cpu占用率高）


	//创建的socket默认是阻塞的，所以发送和接收都是阻塞的
	//设置socket为非阻塞模式（不推荐使用，cpu占用率非常高）
	/*u_long iMode = 1;
	ioctlsocket(s, FIONBIO, &iMode);*/

	//发送的阻塞和非阻塞
	//阻塞发送：发送缓冲区的空间不足够大的时候，等缓冲区足够大的时候再往里面拷贝数据
	//非阻塞发送：发送缓冲区空间不足够大的时候，缓冲区有多大空间就先拷贝多大的数据，剩下没拷贝进去的数据由执行程序自行处理


	//UDP协议特点：
	//1.面向非连接，接收数据的时候，可以接受任意客户端发来的数据，可以是1对1，也可以是1对多
	//2.通讯方式，数据报文通讯方式，数据包不可拆分
	//3.传输效率高（跟TCP协议对比明显）
	//4.会产生丢包，没有校验检查，还可能会出现乱序



	while (true)
	{
		//4.接收数据（阻塞函数，等待的事情没有发生就一直在这等着）
		nRecvNum/*接收到的数据的字节数*/ = recvfrom(s,
			recvBuf/*准备接收数据空间的起始地址*/, 
			sizeof(recvBuf)/*准备接受数据空间的长度*/, 
			0/*初始化标志位，0是采用默认方式接收*/,
			(sockaddr*)&addrFrom/*发送数据的设备的地址信息*/,
			&size/*上一个参数指针指向空间的大小*/);
		if (nRecvNum>0)
		{
			//接收到数据成功,打印接收到的数据和对端的ip
			cout << "ip:"<< inet_ntoa(addrFrom.sin_addr) <<": "<<recvBuf <<endl;
			//ip有两个类型：字符串类型和ulong类型
			//inet_ntoa()：从ulong转换到字符串
			//inet_addr()：从字符串转换到ulong
		}
		else if(WSAGetLastError() != 10035)   //非阻塞接收，错误码等于10035只是暂时没有数据，不是真正的有错误
		{
			//接收数据失败
			cout << "recvfrom error:" << WSAGetLastError()/*打印错误码*/ << endl;
			break;
		}

		////从界面输入数据
		//cin >> sendBuf;
		////5.发送数据
		//nSendNum = sendto(s,sendBuf,strlen(sendBuf) + 1,0,(sockaddr*)&addrFrom,size);
		//if (nSendNum == SOCKET_ERROR)
		//{
		//	cout << "sendto error:" << WSAGetLastError()/*打印错误码*/ << endl;
		//	break;
		//}
	}


	//6.关闭套接字
	closesocket(s);

	//7.卸载库
	WSACleanup();

	return 0;
}

//未定义标识符:编译器不认识函数--没有包含头文件(调用别人的函数) 
//没有在头文件声明函数(调用自己写的函数)
//无法解析的外部符号:编译器找不到函数实现
//如果是自己的函数找不到函数实现，就是没有在cpp中实现
//如果不是自己的函数，没有导入依赖库
//
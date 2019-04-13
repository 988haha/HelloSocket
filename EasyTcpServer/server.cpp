#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

//#pragma comment(lib,"WS2_32.lib")
int main (){
	//启动windows socket 2.x环境
	WORD ver = MAKEWORD(2,2);
	WSADATA dat;
	WSAStartup(ver,&dat);
	

	// 用Socket API 建立简易Tcp客户端
	//1 创建一个socket
	
	//2连接服务器
	
	//3接收服务器信息
	//4关闭套接字
	
	//用SocketAPI建立简易Tcp服务器
	//1建立一个socket
	SOCKET _sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//2bind 绑定用于接收客户端连接的网络端口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net unsigned short;
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (SOCKET_ERROR == bind(_sock,(sockaddr*)&_sin,sizeof(_sin)))
	{
		printf("ERROR,绑定用于接受客户端连接的网络端口失败\n");
	}else{
		printf("绑定端口成功。。。\n");
	}
	//3listen 监听网络端口
	if (SOCKET_ERROR == listen(_sock,5))
	{
		printf("错误，监听端口失败。。。\n");
	} 
	else
	{
		printf("监听端口成功。..\n");
	}
	
	//4accpet等待接收客户端连接
	sockaddr_in clientAdde={};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _cSock = INVALID_SOCKET;
	while (true	)
	{
		_cSock = accept(_sock,(sockaddr*)&clientAdde,&nAddrLen);
		if (INVALID_SOCKET ==_cSock)
		{
			printf("错误，接受无效的客户端 SOCKET..\n");
		}
		printf("新客户端加入：IP = %s \n",inet_ntoa(clientAdde.sin_addr));
		//5send 向客户端发送一条数据
		char msgBuf[]="Hello,I'm Server";
		send(_cSock,msgBuf,strlen(msgBuf)+1,0);
	}
	
	//6关闭套接字closesocket
	closesocket(_sock);
	//--------------

	//清除Windows socket 环境
	WSACleanup();
		return 0;
}
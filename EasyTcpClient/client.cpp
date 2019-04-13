#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

	#pragma comment(lib,"WS2_32.lib")
	int main (){
		//启动windows socket 2.x环境
		WORD ver = MAKEWORD(2,2);
		WSADATA dat;
		WSAStartup(ver,&dat);


		// 用Socket API 建立简易Tcp客户端
		//1 创建一个socket
		SOCKET _sock = socket(AF_INET,SOCK_STREAM,0);
		if (INVALID_SOCKET == _sock)
		{
			printf("错误，建立socket失败。。。\n");
		} 
		else
		{
			printf("建立socket成功！！\n");
		}
		//2连接服务器
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(4567);
		_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		int	ret =  connect(_sock,(sockaddr*)&_sin,sizeof(sockaddr_in));
		if (INVALID_SOCKET == ret)
		{
			printf("错误，建立socket失败。。。\n");
		} 
		else
		{
			printf("建立socket成功。。。\n");
		}
		//3接收服务器信息
		char recvBuf[256] = {};
		int nlen = recv(_sock,recvBuf,256,0);
		if (nlen > 0 )
		{
			printf("接收到数据：%s \n",recvBuf);
		}
		//4关闭套接字
		closesocket(_sock);
		WSACleanup();
		getchar();
		return 0;
}
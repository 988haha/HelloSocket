#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

	#pragma comment(lib,"WS2_32.lib")
	int main (){
		//����windows socket 2.x����
		WORD ver = MAKEWORD(2,2);
		WSADATA dat;
		WSAStartup(ver,&dat);


		// ��Socket API ��������Tcp�ͻ���
		//1 ����һ��socket
		SOCKET _sock = socket(AF_INET,SOCK_STREAM,0);
		if (INVALID_SOCKET == _sock)
		{
			printf("���󣬽���socketʧ�ܡ�����\n");
		} 
		else
		{
			printf("����socket�ɹ�����\n");
		}
		//2���ӷ�����
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(4567);
		_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		int	ret =  connect(_sock,(sockaddr*)&_sin,sizeof(sockaddr_in));
		if (INVALID_SOCKET == ret)
		{
			printf("���󣬽���socketʧ�ܡ�����\n");
		} 
		else
		{
			printf("����socket�ɹ�������\n");
		}
		//3���շ�������Ϣ
		char recvBuf[256] = {};
		int nlen = recv(_sock,recvBuf,256,0);
		if (nlen > 0 )
		{
			printf("���յ����ݣ�%s \n",recvBuf);
		}
		//4�ر��׽���
		closesocket(_sock);
		WSACleanup();
		getchar();
		return 0;
}
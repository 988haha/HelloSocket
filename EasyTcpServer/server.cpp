#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

//#pragma comment(lib,"WS2_32.lib")
int main (){
	//����windows socket 2.x����
	WORD ver = MAKEWORD(2,2);
	WSADATA dat;
	WSAStartup(ver,&dat);
	

	// ��Socket API ��������Tcp�ͻ���
	//1 ����һ��socket
	
	//2���ӷ�����
	
	//3���շ�������Ϣ
	//4�ر��׽���
	
	//��SocketAPI��������Tcp������
	//1����һ��socket
	SOCKET _sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//2bind �����ڽ��տͻ������ӵ�����˿�
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net unsigned short;
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (SOCKET_ERROR == bind(_sock,(sockaddr*)&_sin,sizeof(_sin)))
	{
		printf("ERROR,�����ڽ��ܿͻ������ӵ�����˿�ʧ��\n");
	}else{
		printf("�󶨶˿ڳɹ�������\n");
	}
	//3listen ��������˿�
	if (SOCKET_ERROR == listen(_sock,5))
	{
		printf("���󣬼����˿�ʧ�ܡ�����\n");
	} 
	else
	{
		printf("�����˿ڳɹ���..\n");
	}
	
	//4accpet�ȴ����տͻ�������
	sockaddr_in clientAdde={};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _cSock = INVALID_SOCKET;
	while (true	)
	{
		_cSock = accept(_sock,(sockaddr*)&clientAdde,&nAddrLen);
		if (INVALID_SOCKET ==_cSock)
		{
			printf("���󣬽�����Ч�Ŀͻ��� SOCKET..\n");
		}
		printf("�¿ͻ��˼��룺IP = %s \n",inet_ntoa(clientAdde.sin_addr));
		//5send ��ͻ��˷���һ������
		char msgBuf[]="Hello,I'm Server";
		send(_cSock,msgBuf,strlen(msgBuf)+1,0);
	}
	
	//6�ر��׽���closesocket
	closesocket(_sock);
	//--------------

	//���Windows socket ����
	WSACleanup();
		return 0;
}
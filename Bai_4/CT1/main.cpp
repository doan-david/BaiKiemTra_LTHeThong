#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
int main()
{
	WSADATA wsaData;
	SOCKADDR_IN rAddr;
	int iRc;
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);
	rAddr.sin_family = AF_INET;
	rAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	rAddr.sin_port = htons(1024);
	iRc = connect(sk, (LPSOCKADDR)&rAddr, sizeof(rAddr));
	while(1)
	{
		char st[256];
		float a[100];
		int n;
		printf("Nhap so phan tu:");
		scanf("%d",&n);
		for(int i=0;i <n;i++)
			scanf("%f",&a[i]);		
		send(sk,(const char*)&n, sizeof(n), 0);
		if(n<0)
			break;
		send(sk,(const char*)a, n*sizeof(float), 0);
	}
	closesocket(sk);
	WSACleanup();
	
	getch();	
    return 0;
}

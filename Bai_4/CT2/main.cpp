#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
int main()
{
	WSADATA wsaData;
	SOCKADDR_IN serAddr, cliAddr;
	int iRc;
	int adsize;
	char buffer[256];
	iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serAddr.sin_port = htons(1024);
	iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
	iRc = listen(ssk, 5);
	adsize = sizeof(cliAddr);
	SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);
	while(1)
	{
		int n;
		float a[100];
		recv(sk,(char*)&n, sizeof(n), 0);
		if(n< 0)
			break;
		printf("n=%d\n",n);
		recv(sk,(char*)a, n*sizeof(float), 0);
		for(int i=0;i < n;i++)
			printf("%f ",a[i]);
		printf("\n");		
	}
	closesocket(sk);
	closesocket(ssk);
	WSACleanup();
	getch();
	return 0;
}

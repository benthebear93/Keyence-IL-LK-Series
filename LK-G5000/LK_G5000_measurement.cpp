#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
#pragma comment(lib, "WS2_32.LIB")
#define KEYENCE "192.168.10.10"
#define KEYENCE_PORT 24687
void PrintHexa(char* buff, size_t len);

void main() {
	SOCKET sock; WSADATA wsa;
	struct sockaddr_in sock_addr;
	int ret = 0;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&sock_addr, 0, sizeof(sock_addr));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = inet_addr(KEYENCE);
	sock_addr.sin_port = htons(KEYENCE_PORT);
	
	char LK_GetMeasurementValue[] = { 0x07, 0x00, 0x07, 0x14, 0x00, 0x00, 0x00 };
	size_t LK_GetMeasurementValue_s = sizeof(LK_GetMeasurementValue);
	char OutputMeasurement[116];
	if (connect(sock, (struct sockaddr*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR) {
		perror("connect()");
		closesocket(sock);
		WSACleanup();
		return;
	}
	while (1) {
		if (send(sock, LK_GetMeasurementValue, LK_GetMeasurementValue_s, 0) == SOCKET_ERROR) {
			perror("send()");
			closesocket(sock);
			WSACleanup();
			return;
		}
		ret = recv(sock, OutputMeasurement, 116, 0);
		if (ret == SOCKET_ERROR) {
			perror("recv()"); closesocket(sock); WSACleanup();
			return;
		}
		int byte, byte2;
		double outMeasurementValueMM;
		byte = (unsigned char)OutputMeasurement[68];
		byte2 = (unsigned char)OutputMeasurement[69];
		outMeasurementValueMM = byte2 << 8 | byte;
		printf("out put : %f mm\n", outMeasurementValueMM/1000.0);
	}
	closesocket(sock);
	WSACleanup();
	system("pause");
}

void PrintHexa(char* buff, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
	{
		printf("%02X ", (unsigned char)buff[i]);
		if (i % 8 == 0 && i !=0)
		{
			printf("\n");
		}
	}
	printf("\n");
}
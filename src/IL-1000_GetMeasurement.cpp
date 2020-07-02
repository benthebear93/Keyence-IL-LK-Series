#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <math.h>

using namespace std;
#pragma comment(lib, "WS2_32.LIB")
#define KEYENCE "192.168.0.30"
#define KEYENCE_PORT 64000
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

   char IL_GetMeasurementValue[] = { 0x4D, 0x30, 0x0D, 0x0A }; // register, register, CR, LF
   size_t IL_GetMeasurementValue_s = sizeof(IL_GetMeasurementValue);
   char OutputMeasurement[15];

   if (connect(sock, (struct sockaddr*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR) {
      perror("connect()");
      closesocket(sock);
      WSACleanup();
      return;
   }
   while (1) {
      if (send(sock, IL_GetMeasurementValue, IL_GetMeasurementValue_s, 0) == SOCKET_ERROR) {
         perror("send()");
         closesocket(sock);
         WSACleanup();
         return;
      }
      ret = recv(sock, OutputMeasurement, 15, 0);
      if (ret == SOCKET_ERROR) {
         perror("recv()"); closesocket(sock); WSACleanup();
         return;
      }
      //PrintHexa(OutputMeasurement, ret);
      int msb = 0, data = 0;
      double OutputMeasurement_mm = 0;
      msb = OutputMeasurement[3];
      data = OutputMeasurement[8] - '0';
      for (int i = 0; i < 5; i++) {
         data = OutputMeasurement[8 + i] - '0';
         OutputMeasurement_mm += data * 10 * pow(0.1, i);
      }
      cout << "Output mm : " << OutputMeasurement_mm << endl;
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
   }
   printf("\n");
}
//
// Created by adora on 2024-02-09.
// 819 Elevator, 802 fundamental

// Convert IP Address to long
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global
typedef union
{
    unsigned char chAddr[4];
    unsigned long numAddr;
} IP_ADDR;

int main(void)
{
    // Local
    IP_ADDR addr;
    // mean is We call, Ip_ADDR == addr
    char* parser;
    char strAddr[16];

    // Statement
    printf("Enter the Your IP Address (ex: format: xxx.xxx.xxx.xxx): ");
    scanf("%15s", strAddr); // if you Over => Overflow


    parser = strtok(strAddr, ".");
    addr.chAddr[3] = strtol(parser,(char**)NULL,10);
    // strtol == string Change integer
    // (const char *str, char **endptr(EndPoint), jinsu)

    for (int i = 2; i >= 0; i--)
    {
        // Convert
        parser = strtok(NULL, ".");
        addr.chAddr[i] = strtol(parser, (char**)NULL, 10);
    }

    // print
    printf("IP decimal set : %d.%d.%d.%d\n",
           addr.chAddr[3], addr.chAddr[2],
           addr.chAddr[1], addr.chAddr[0]);
    printf("IP Binary Changed : %lu\n", addr.numAddr);
    return 0;

}

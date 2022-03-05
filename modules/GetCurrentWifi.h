#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STATEPATH "/sys/class/net/wlp2s0/operstate"
//#define NETWORKSSIDPATH "sys/class/net/wlp2s0/"

void GetCurrentWifiState(char* out, int len) {
	FILE* fp = fopen(STATEPATH, "r");
	if(fp == NULL) {
		perror("Failed to open operstate path");
	}
	fread(out, len, 1,fp);
	fclose(fp);
	
	// Remove \n char at the end of the string
	out[len - 3] = '\0';
}

void GetCurrentWifiSSID(char* out, int len) {
	
}

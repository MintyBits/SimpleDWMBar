#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Change this to whatever the path to your battery's capacity file is in case you don't have the same path.
#define BatteryCapacityPath "/sys/class/power_supply/BAT0/capacity"
#define BatteryStatusPath "/sys/class/power_supply/BAT0/status"

void GetCurrentBatteryStatus(char* out, int len) {
	FILE* fp = fopen(BatteryStatusPath, "r");
	if(fp == NULL) {
		perror("Failure to open battery status path");
	}
	fgets(out, len, fp);
	fclose(fp);

	out[strlen(out) - 1] = '\0';
}

void GetCurrentBatteryPercentage(char* out, int len) {
	FILE* fp = fopen(BatteryCapacityPath, "r");
	if(fp == NULL) {
		perror("Failure to open battery percentage path");
	}
	fgets(out, len, fp);
	fclose(fp);

	out[strlen(out) - 1] = '\0';
}

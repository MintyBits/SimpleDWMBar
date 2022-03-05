#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "modules/GetCurrentTime.h"
#include "modules/GetCurrentBattery.h"
//#include "modules/GetCurrentWifi.h"
#include "modules/GetCurrentUser.h"

#define DEFBUFLEN 64

int main() {
	while(1) {
		char DwmTopBuffer[1024];

		char CurrentBatteryPercentage[DEFBUFLEN];
		char CurrentBatteryStatus[DEFBUFLEN];
		char CurrentTime[DEFBUFLEN];
		char CurrentUser[DEFBUFLEN];

		GetCurrentTime(CurrentTime, DEFBUFLEN);
		GetCurrentBatteryStatus(CurrentBatteryStatus, DEFBUFLEN);
		GetCurrentBatteryPercentage(CurrentBatteryPercentage, DEFBUFLEN);
		GetCurrentUser(CurrentUser, DEFBUFLEN);

		// Format a command using all the information we have detected.
		// NOTE: You can add some cool utf-8 icons into this and have the coolest rice to put on r/unixporn
		snprintf(DwmTopBuffer, 1024, "xsetroot -name '[Battery: %s%% | %s] [Time: %s] [User: %s]'", CurrentBatteryPercentage, CurrentBatteryStatus, CurrentTime, CurrentUser);
		system(DwmTopBuffer);
		
		// Don't remove this...
		sleep(1);
	}
	return 0;
}

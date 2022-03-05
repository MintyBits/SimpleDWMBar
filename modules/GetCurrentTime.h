#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void GetCurrentTime(char* out, int maxlen) {
	time_t CurrentTimeT = time(NULL);
	
	char *CurrentTimeString = ctime(&CurrentTimeT);
	CurrentTimeString[strlen(CurrentTimeString) -1] = '\0';

	strncpy(out, CurrentTimeString, maxlen);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The only reason this exists if because it looks better...
void GetCurrentUser(char* out, int len) {
	getlogin_r(out, len);
} 

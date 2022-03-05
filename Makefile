build: main.c modules/GetCurrentBattery.h modules/GetCurrentTime.h modules/GetCurrentWifi.h
	gcc main.c -o build/dwm-bar

install: main.c
	gcc main.c -o /usr/bin/dwm-bar

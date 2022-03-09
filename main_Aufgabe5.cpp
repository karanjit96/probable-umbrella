// --------------------------------------------------------------------------
// SWE3 CanParser - Aufgabe 5
//
// Bearbeitet von:
//     Name, Matrikelnummer
//     Name, Matrikelnummer
//
// --------------------------------------------------------------------------

// Lokale Header
#include <stdio.h>      // printf(), perror()
#include <stdlib.h>     // exit()
#include <unistd.h>     // write()
#include <fcntl.h>      // O_RDONLY
#include <linux/can.h>  // struct can_frame
#include "lib/can.h"    // can_open()
#include <iostream>

// Feste Definitionen für dieses Programm
#define CAN_INTERFACE    "vcan0"
#define LOG_FILE         "logs/20121011_bmw_stopngo_5min.raw"

struct timevalx
{
	int64_t tv_sec;
	int64_t tv_usec;
};

// Diese Datenstruktur repräsentiert einen einzelnen Eintrag in der Log-Datei.
struct log_entry
{
	struct timevalx   timeval;
	struct can_frame  can_frame;
};

int main (void)
{
	// Socket mit dem angegebenen CAN-Interface öffnen, danach kann
	// mit read() und write() auf das Interface zugegriffen werden.
	int fd_can;
	fd_can = can_open("vcan0");

	// Log-Datei öffnen. Hier sind die Daten in Form von struct log_entry
	// Einträgen hinterlegt, die nacheinander mit read() lesbar sind.
	int fd_log;
	fd_log = open(LOG_FILE, O_RDONLY,0660);

	// Einzelnen Log-Eintrag auslesen.
	struct log_entry entry;
	//for(long unsigned int i{};i<=sizeof(LOG_FILE);i++)
	int fd{};
	long int t1,t2{};

	do{
	fd=read(fd_log, &entry, sizeof(struct log_entry));
	if(fd==0){
		break;
	}
	t1=entry.timeval.tv_sec*1000000+entry.timeval.tv_usec;
	std::cout<<" T1. "<<t1<<" T2: "<<t2<<" Diff: "<<t1-t2<<std::endl;


	// Eine einzelne Nachricht an das CAN-Interface senden.
	// Als Inhalt dient das can_frame innerhalb der log_entry Struktur.

	write(fd_can, &entry.can_frame, sizeof(struct can_frame));
	if(t2==0){
		t2=t1;
		continue;
	}
	usleep(t1-t2);
	t2=t1;
	}while(true);
	// Programm beenden
	return 0;
}

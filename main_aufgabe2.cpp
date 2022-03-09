// --------------------------------------------------------------------------
// SWE3 CanParser - Aufgabe 1
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
#include <linux/can.h>  // struct can_frame
#include "lib/can.h"    // can_open()
#include <iostream>

int main (void)
{
	// Socket mit dem angegebenen CAN-Interface öffnen, danach kann
	// mit read() und write() auf das Interface zugegriffen werden.
	int fd_can;
	fd_can = can_open("vcan0");

// frame1
	// Diese Datenstruktur enthält eine einzelne CAN-Nachricht,
	// deren Inhalt wir nach Belieben festlegen können.
	for(int j{};;j++){
	struct can_frame frame1;
	frame1.can_id  = 0x123;
	frame1.can_dlc = 4;       // Anzahl der Datenbytes.
	for (int i{}; i<4;i++){

	frame1.data[i] = 0x01+i*j;    // Datenbyte 1
	}

	// Mithilfe des Befehls write() können eine einzelne Nachricht
	// an das CAN-Interface senden, als Inhalt verwenden wir dazu
	// unsere vorher angelegte Datenstruktur.
	write(fd_can, &frame1, sizeof(struct can_frame));
	usleep(200* 1000);
//frame2
	/*struct can_frame frame2;
	frame2.can_id  = 0x130;
	frame2.can_dlc = 8;       // Anzahl der Datenbytes.
	for (int i{}; i<7;i++){

	frame2.data[i] = 0x03*i+j;    // Datenbyte 1
	}*/

	// Mithilfe des Befehls write() können eine einzelne Nachricht
	// an das CAN-Interface senden, als Inhalt verwenden wir dazu
	// unsere vorher angelegte Datenstruktur.
	//int errorcheck=write(fd_can, &frame2, sizeof(struct can_frame));
	//usleep(200*1000);
/*	int fd_read = read(fd_can, &frame2, sizeof(struct can_frame));
		if(fd_read<=0){
			printf("Error no data");
		}
		else{
			printf("Success");
		}*/
//Fail check
	/*if(errorcheck<0){
		//perror("write situation ");
		std::cout << "error" << std::endl;
		exit(-1);
	}else{
		//perror("write situation ");
		std::cout << "Success" << std::endl;
		}*/
	}

	// Programm beenden
	return 0;
}

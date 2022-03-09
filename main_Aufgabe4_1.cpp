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
#include <fcntl.h>

int counter{1};
int main (void)
{
	// Socket mit dem angegebenen CAN-Interface öffnen, danach kann
	// mit read() und write() auf das Interface zugegriffen werden.
	int fd_can;
	fd_can = can_open("vcan0");

	int fd_text;
	fd_text=open("./test.bin", O_WRONLY | O_CREAT, 0660);
	if(fd_text<0){
		std::cout<<"File open failed"<<std::endl;
		exit(-1);
	}else{
		std::cout<<"File open Pass "<<fd_text<<std::endl;
	};
while(counter<11){
	// Diese Datenstruktur enthält eine einzelne CAN-Nachricht,
	// deren Inhalt wir nach Belieben festlegen können.
	struct can_frame frame;
	frame.can_id  = 0x123+counter;
	frame.can_dlc = 4;       // Anzahl der Datenbytes.
	frame.data[0] = 0x00+counter;    // Datenbyte 1
	frame.data[1] = 0x01+counter;    // Datenbyte 2
	frame.data[2] = 0x02+counter;    // ..
	frame.data[3] = 0x03+counter;

	// Mithilfe des Befehls write() können eine einzelne Nachricht
	// an das CAN-Interface senden, als Inhalt verwenden wir dazu
	// unsere vorher angelegte Datenstruktur.
	write(fd_can, &frame, sizeof(struct can_frame));
	int ret=write(fd_text,&frame, sizeof(frame));
	std::cout<<counter;
	if(ret<0){
		std::cout<<" File writing failed"<<std::endl;
		exit(-1);
	}else{
		std::cout<<" File writing Passed "<<ret<<std::endl;
	};
	counter++;
}
	// Programm beenden
	return 0;
}

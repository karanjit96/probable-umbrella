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
using namespace std;

int main (void)
{
	// Socket mit dem angegebenen CAN-Interface öffnen, danach kann
	// mit read() und write() auf das Interface zugegriffen werden.
	int fd_can;
	fd_can = can_open("vcan0");
	struct can_frame frame;

while(1){

	// Mithilfe des Befehls Read() können eine einzelne Nachricht
	// von dem CAN-Interface gelesen werden
	read(fd_can, &frame, sizeof(struct can_frame));
	cout<<"Read: ";
	for(int i{};i<4;i++){
		cout<<frame.data[i];
	}
	cout<<endl;

}
	// Programm beenden
	return 0;
}

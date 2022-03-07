
// main.cpp
// Created by Karanjit Singh on 07.03.22.
//Discribtion: 


#include "Global.h"
#include "CBinarySemaphore.h"
#include "CSharedMemory.h"
#include <pthread.h>
#include <new>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "CContainer.h"
using namespace std;

CSharedMemory SHM1("SHM_1", sizeof(CContainer));
CContainer*ptr = new (SHM1.mPtr)CContainer;

void *main_producer(void *);		//Declaring function for threading
void *main_consumer(void *);		//Declaring function for threading
void main_consumer2();			//Declaring function for threading

int main() {
	pthread_t tid1, tid2;
	pthread_create(&tid1, 0, main_producer, 0);
	pthread_create(&tid2, 0, main_consumer, 0);
//	main_consumer2();
	
	pthread_join(tid1, 0);
	pthread_join(tid2, 0);
	
	return 0;
}

void *main_producer(void *){		//Defining function for threading
	for(int i{}; i<20;i++){
		ptr->set_data(1);
	}
};		
void *main_consumer(void *){		//Defining function for threading	
	for(int j{}; j<20;j++){
		ptr->get_data();
	}
};

void main_consumer2(){		//Defining function for threading	
	for(int k{}; k<2000;k++){
		ptr->get_data();
	}
};		
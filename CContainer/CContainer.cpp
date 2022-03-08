//
// CContainer.cpp
// Created by Karanjit Singh on 07.03.22.

#include "CContainer.h"
#include "CBinarySemaphore.h"
int value{};
CContainer::CContainer():read(false, true), write(true, true){	//List-Intialising Semaphores
}

CContainer::~CContainer(){	
}

void CContainer:: set_data(int pData){		//setter to set data in the Array
	write.take();
	for (int i{}; i<=ARRAY_SIZE; i++){
		value=mData[i]= pData+i;
		cout<<"Producer writing: "<<value<<endl;
	}
	read.give();
}

void CContainer::get_data(){					//getter to take the data from Array
	read.take();
	for (int i{}; i<=ARRAY_SIZE; i++){
		cout<<"Consumer: "<<mData[i]<<endl;	
	}
	
	write.give();
}
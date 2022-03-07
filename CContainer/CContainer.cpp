//
// CContainer.cpp
// Created by Karanjit Singh on 07.03.22.

#include "CContainer.h"
#include "CBinarySemaphore.h"
int value{};
CContainer::CContainer():read(false, true), write(true, true){	
}

CContainer::~CContainer(){	
}

void CContainer:: set_data(int pData){
	write.take();
	for (int i{}; i<=ARRAY_SIZE; i++){
		value=mData[i]= pData*i;
		cout<<"Producing number "<<value<<endl;
	}
	read.give();
}

void CContainer::get_data(){
	read.take();
	for (int i{}; i<=ARRAY_SIZE; i++){
		cout<<"Consumer "<<mData[i]<<endl;	
	}
	
	write.give();
}
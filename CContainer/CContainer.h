//
// CContainer.h
// Created by Karanjit Singh on 07.03.22.

#ifndef _CContainer_h_
#define _CContainer_h_
#include "CBinarySemaphore.h"
#include <iostream>
using namespace std;

#define ARRAY_SIZE 2

class CContainer{
public:
	CContainer();						//Constructor with 0 parameter 
	~CContainer();						//Desructor
	void set_data(int pData);			//Setter
	void get_data();					//Getter
	
public:
	int mData[ARRAY_SIZE];				//Static array 
	CBinarySemaphore read;				
	CBinarySemaphore write;
};


#endif
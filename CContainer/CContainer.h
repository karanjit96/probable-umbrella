//
// CContainer.h
// Created by Karanjit Singh on 07.03.22.

#ifndef _CContainer_h_
#define _CContainer_h_
#include "Global.h"
#include "CBinarySemaphore.h"
#include "CSharedMemory.h"
#include <pthread.h>
#include <new>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

#define ARRAY_SIZE 2

class CContainer{
public:
	CContainer();
	~CContainer();
	void set_data(int pData);
	void get_data();
	
public:
	int mData[ARRAY_SIZE];
	CBinarySemaphore read;
	CBinarySemaphore write;
};


#endif
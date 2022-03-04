//
// CStack.h
// Created by Karanjit Singh on 28.01.22.

#pragma once
#include "CMessage.h"
#include <iostream>
using namespace std;
#define STACKSIZE 5

class CStack{
public:
	CStack();
	bool add(CMessage &pMsg);
	bool get(CMessage &pMsg);
private:
	CMessage mStack[STACKSIZE];
	unsigned int mIndex;
};
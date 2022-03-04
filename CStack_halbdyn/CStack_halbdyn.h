//
// CStack_halbdyn.h
// Created by Karanjit Singh on 28.01.22.

#pragma once

#include "CMessage.h"
#include <iostream>
using namespace std;

class CStack{
public:
	CStack(int pSize);
	~CStack();
	bool add(CMessage &pMsg);
	bool get(CMessage &pMsg);
	
private:
	int mSize;
	int mIndex;
	CMessage *mStackptr;
};
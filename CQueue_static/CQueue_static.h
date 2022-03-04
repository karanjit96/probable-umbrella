//
// CQueue_static.h
// Created by Karanjit Singh on 28.01.22.

#pragma once
#include <iostream>
#include "CMessage.h"
#define QSIZE 5

using namespace std;

class CQueue{
public:
	CQueue();
	bool add(CMessage &pMsg);
	bool get(CMessage &pMsg);
private:
	int mCurrentsize;
	int mTailindex;
	int mHeadindex;
	CMessage myQueue[QSIZE];
};

//
// CStack_dyn.h
// Created by Karanjit Singh on 28.01.22.

#pragma once
#include "CMessage.h"
#include <iostream>
using namespace std;

class CStack_dyn{
public:
	CStack_dyn();
	CStack_dyn(CMessage pMsg);
	~CStack_dyn();
	bool add(CMessage &pMsg);
	bool get(CMessage &pMsg);
	
private:
	CMessage mMsg;
	CStack_dyn *mNextptr;
};

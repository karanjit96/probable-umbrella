//
// CStack.cpp
// Created by Karanjit Singh on 28.01.22.

#include "CStack.h"

CStack::CStack(){
	mIndex=0;
};
bool CStack::add(CMessage &pMsg){
	if(mIndex==STACKSIZE)		//stack voll
	return false;
	else{
		mStack[mIndex]=pMsg;
		mIndex++;
		return true;
	}
};
bool CStack::get(CMessage &pMsg){
	if(mIndex==0)		//stack leer
	return false;
	else{
		mIndex--;
		pMsg=mStack[mIndex];
	return true;
	}
};

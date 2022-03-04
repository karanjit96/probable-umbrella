//
// CStack_halbdyn.cpp
// Created by Karanjit Singh on 28.01.22.

#include "CStack_halbdyn.h"

CStack::CStack(int pSize){
	mSize=pSize;
	mIndex=0;
	mStackptr= new CMessage[mSize];
};

CStack::~CStack(){
	delete [] mStackptr;
};
bool CStack::add(CMessage &pMsg){
	if(mIndex==mSize)
		return false;			//stack voll
	else{
		mStackptr[mIndex]=pMsg;
		mIndex++;
		return true;
	}
};
bool CStack::get(CMessage &pMsg){
	if(mIndex==0)
		return false;			//stack empty
	else{
		mIndex--;
		pMsg=mStackptr[mIndex];
		return true;
	}
};
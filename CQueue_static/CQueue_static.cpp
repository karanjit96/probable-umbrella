//
// CQueue_static.cpp
// Created by Karanjit Singh on 28.01.22.

#include "CQueue_static.h"

CQueue::CQueue(){
	mCurrentsize=0;
	mTailindex=0;
	mHeadindex=0;
};
bool CQueue::add(CMessage &pMsg){
	if(mCurrentsize==QSIZE)			//queue voll
	return false;
	else{
		myQueue[mTailindex]=pMsg;
		mTailindex++;
		mCurrentsize++;
		mTailindex=mTailindex%QSIZE;		//Wraparound
	
	return true;
	}
};
bool CQueue::get(CMessage &pMsg){
	if(mCurrentsize==0)				//leer
	return false;
	else{
		pMsg=myQueue[mHeadindex];
		mHeadindex++;
		mHeadindex=mHeadindex%QSIZE;
		mCurrentsize--;
		return true;
	}
};
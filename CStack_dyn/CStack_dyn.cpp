//
// CStack_dyn.cpp
// Created by Karanjit Singh on 28.01.22.

#include "CStack_dyn.h"
CStack_dyn::CStack_dyn(){
	mMsg.mData=0;
	mMsg.mID=0;
	mNextptr= NULL;
};

CStack_dyn::CStack_dyn(CMessage pMsg){
	mMsg=pMsg;
	mNextptr=NULL;
};

CStack_dyn::~CStack_dyn(){
	while(mNextptr!=NULL){
		CMessage Dummymsg;
		get(Dummymsg);
	}
		
};
bool CStack_dyn::add(CMessage &pMsg){		//write PUSH into stack
	CStack_dyn *tempptr= new CStack_dyn(pMsg);		//create new node
	tempptr->mNextptr=mNextptr;		//chain end of new node
	mNextptr=tempptr;				//chain front of new node
	return true;
};
bool CStack_dyn::get(CMessage &pMsg){
	if(mNextptr==NULL)		//empty
	return false; 
	
	pMsg=mNextptr->mMsg;			//read message
	CStack_dyn *tempptr =mNextptr;	//copy ptr to TOS
	mNextptr=mNextptr->mNextptr;	//my Nextptr 
	
	return true;
};

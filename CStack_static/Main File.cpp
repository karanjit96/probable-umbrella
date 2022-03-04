
// Main File.cpp
// Created by Karanjit Singh on 28.01.22.
//Discribtion: 

#include <iostream>
#include "CStack.h"
using namespace std;

int main() {
	CMessage msg0;
	CStack mystack;
	
	msg0.mID=0;
	msg0.mData=0;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	msg0.mData=1;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	msg0.mData=2;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	msg0.mData=3;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	msg0.mData=4;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	msg0.mData=5;
	cout<<mystack.add(msg0)<<" "<<msg0.mData<<endl;
	cout<<endl;
	
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;
	cout<<mystack.get(msg0)<<" "<<msg0.mData<<endl;

	
	return 0;
}
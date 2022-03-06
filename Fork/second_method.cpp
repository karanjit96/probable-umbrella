
// secon_method.cpp
// Created by Karanjit Singh on 06.03.22.
//Discribtion: 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;
pid_t fork();

int main() {
	int cnt1;
	int cnt2;
	if(fork()==0){
		int i=0;
		while(1){
			printf("Son 1; Cnt1:%p; Cnt2:%d; Cnt2:%p ", &cnt1, ++cnt2, &cnt2);
			i++;
			cout<<endl;
		}	}
	else if(fork() ==0){
		int p=0;
		while(1){
			printf("Son 2; Cnt1:%p; Cnt2:%d; Cnt2:%p ", &cnt1, ++cnt2, &cnt2);
			cout<<endl;
			p++;
			
	}}
	else{
		int i=0;
		while(1){
			printf("Father; Cnt1:%p; Cnt2:%d; Cnt2:%p ", &cnt1, ++cnt2, &cnt2);
			cout<<endl;
			i++;
			
	}}
	
	return 0;
}
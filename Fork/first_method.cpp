
// Main File.cpp
// Created by Karanjit Singh on 06.03.22.
//Discribtion: creating 2 processes with Fork. every process has its own main_x(), which will be called after fork()
//printing some text in both fork using printf() or cout

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


using namespace std;


void main_son(){
	for (int a{}; a<1000; a++){
		cout<<" Son  "<<a<<endl;
	}
}

void main_father(){
	for (int b{}; b<1000; b++){
		cout<<" Father  "<<b<<endl;
	}
}


int main() {
	pid_t pid;
	pid = fork();
	
	if(fork() == 0){
		main_son();
	}
	else{
		main_father();
	}
	return 0;
}
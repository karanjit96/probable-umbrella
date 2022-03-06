
// Main File.cpp
// Created by Karanjit Singh on 06.03.22.
//Discribtion: 

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* main_son1(void *){
	for (int a{};a<1000;a++){
		cout<<"Son 1 "<<a<<endl;
	}
}
void* main_son2(void *){
	for (int a{};a<1000;a++){
		cout<<"Son 2 "<<a<<endl;
	}
}

void* main_father(){
	for (int b{};b<1000;b++){
		cout<<"father "<<b<<endl;
	}
}


int main() {
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, 0, main_son1, 0);
	pthread_create(&thread1, 0, main_son2, 0);

	pthread_join(thread1, 0);

	pthread_join(thread2, 0);

	
	
	return 0;
}
//Homework3
//Part 2
//Abdul Samad Khan
//5 functions are declared in this class
//2 private variables are declared in this class
#pragma once
#include<iostream>
using namespace std;
class Guest {

	private:
		char lastName[30];
		char firstName[30];
	
	public:
		Guest();
		Guest(char *);
		char* getLastName();
		char* getFirstName();
		char* toString();
};

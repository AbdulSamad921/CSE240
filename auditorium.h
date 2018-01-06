//Homework3
//Part 2
//Abdul Samad Khan
//Five functions are declared in this class to be used in auditorium.cpp

#include<iostream>
#include "guest.h"
using namespace std;
class Auditorium
{
	private:
		Guest **seating;
	public:
		Auditorium(int, int);
		Guest* getGuestAt(int, int);
		bool assignGuestAt(int, int, Guest *);
		bool checkBoundaries(int, int);
		char* toString();


};
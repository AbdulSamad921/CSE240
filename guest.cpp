//Homework3
//Part 2
//Abdul Samad Khan
//5 functions are implemented in this file
//default constructor
//constructor with parameter
//firstname retriever
//lastname retriever
//converting name into a string to be assigned value
#include<iostream>
#include"guest.h"
#include<string.h>
#include<string>

using namespace std;
//default constructor
Guest::Guest()
{
	
	strcpy_s(firstName,"???");
	strcpy_s(lastName, "???");
	
}
//constructor with parameters seperatinf firstname and lastname from char array passed as a parameter
Guest::Guest(char *guestInfo)
{

	char *token, *token1;
	//sperating first_name and last_name from the user input i.e info
	token1 = strtok_s(guestInfo, "/",&token);
	strcpy_s(firstName, token1);
	token = strtok_s(NULL, "/",&token);
	strcpy_s(lastName, token);
	

}
//returning fristname
char* Guest::getFirstName()
{
	return firstName;
}
//returning lastname
char* Guest::getLastName()
{
	return lastName;
}
//converting name into ?.?. to be returned
char* Guest::toString()
{
	
	char * p = new char[100];

	p[0] = firstName[0];
	p[1] = '.';
	p[2] = lastName[0];
	p[3] = '.';
	p[4] = ' ';
	p[5] = '\0';
	return p;
	delete p;
}
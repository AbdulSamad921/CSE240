//Homework3
//Part 2
//Abdul Samad Khan
//Five functions are implemented in the following code
//setting default values to each seat 
//Retrieving guestInfo at a particular seat
//Assigning guest to a new seat
//Checking if row and column selected exist inside the boundary
//printing the seating arrangement

#include<iostream>
#include<cstring>
#include"auditorium.h"
#include"guest.h"

using namespace std;

int rowNum1, columnNum1;
//Initializing seats to default type
Auditorium::Auditorium(int rowNum, int columnNum) {
	
	rowNum1 = rowNum;
	columnNum1 = columnNum;
	// making a 2d array in heap 
	seating =new Guest*[rowNum];
	
	for (int i = 0; i < rowNum; i++)
	{
		seating[i] = new Guest[columnNum];
		
	}
	//assigning default value
	for (int i = 0; i < rowNum; ++i)
	{
		for (int j = 0; j < columnNum; ++j)
		{
			seating[i][j] = Guest::Guest();
		}
	}
}
// returning guest on the required seat
Guest * Auditorium::getGuestAt(int rowNum, int columnNum) {

	return &seating[rowNum][columnNum];
	
}

//assiging guest to an empty seat
bool Auditorium::assignGuestAt(int row,int col, Guest* tempGuest){
	


	if ((strcmp(seating[row][col].getFirstName() ,"???")==0)&& (strcmp(seating[row][col].getLastName() , "???")==0))
	{

			
			seating[row][col] = *tempGuest;
			
			return 1;
		

		

	}
	else {
		return 0;

	}
	

}
//checking if the entered seat exist in the intialized array or not
bool Auditorium::checkBoundaries(int row, int col) {

	if ((row < 0 || col < 0) || (row > rowNum1 || col > columnNum1))
	{
		return 0;
	}
	else
		return 1;
}
//returning an array that contains the whole seating information
char* Auditorium::toString(){

	

	char* q = new char[5];
	char* p = new char[150];
	q = {};
	int k = 0;

	cout << "The current seating is\n";
	cout << "-------------------------\n";
	for (int i = 0; i < rowNum1; i++)
	{
		for (int j = 0; j < columnNum1; j++)
		{
			q = seating[i][j].toString();

			p[k] = q[0];
			p[k + 1] = q[1];
			p[k + 2] = q[2];
			p[k + 3] = q[3];
			p[k + 4] = q[4];
			k = k + 5;



		}
		p[k ] = '\n';
		k = k + 1;
		
	}
	p[k] = '\0';
	return p;
	delete p, q;
	
}
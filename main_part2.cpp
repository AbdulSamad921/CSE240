//Homework3
//Part 2
//Abdul Samad Khan
#include<iostream>
#include "guest.h"
#include "auditorium.h"
using namespace std;

void main() {
	Auditorium* auditorium;
	Guest* tempGuest;
	int row, col, rowNum, columnNum;
	char guestInfo[30];
	// Ask a user to enter a number of rows for an auditorium seating
	cout << "Please enter a number of rows for an auditorium seating.";
	cin >> rowNum;
	// Ask a user to enter a number of columns for an auditorium seating
	cout << "Please enter a number of columns for an auditorium seating.";
	cin >> columnNum;
	// auditorium_seating

	auditorium = new Auditorium(rowNum, columnNum);
	cout << "Please enter a guest information or enter \"Q\" to quit.";
	/*** reading a guest's information ***/
	cin >> guestInfo;
	/* we will read line by line **/
	while (strcmp(guestInfo, "Q") != 0) {
		cout << "\nA guest information is read.\n";
		// printing information.
		cout << guestInfo;
		// guest
		tempGuest = new Guest(guestInfo);
		// Ask a user to decide where to seat a guest by asking
		// for row and column of a seat
		cout << "\nPlease enter a row number where the guest wants to sit.\n";
		cin >> row;
		cout << "\nPlease enter a column number where the guest wants to sit.\n";
		cin >> col;
		// Checking if the row number and column number are valid
		// (exist in the theatre that we created.)
		if ((*auditorium).checkBoundaries(row, col) == false) {
			cout << "\nrow or column number is not valid.";
			cout << "A guest" << (*tempGuest).getFirstName() << " " <<
				(*tempGuest).getLastName() << " is not assigned a seat.\n";
		}
		else {
			// Assigning a seat for a guest
			if ((*auditorium).assignGuestAt(row, col, tempGuest) == true) {
				cout << "\nThe seat at row "<< row << " and column " <<
					" is assigned to the guest, " << (*tempGuest).toString();
				cout<<(*auditorium).toString();
			}
			else {
				cout << "\nThe seat at row " << row << " and column " << col << " is taken.\n";
			}
		}
		// Read the next guestInfo
		cout << "Please enter a guest information or enter \"Q\" to quit.\n";
		/*** reading a guest's information ***/
		cin >> guestInfo;
	}
}
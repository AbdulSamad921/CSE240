//Homework2
//Part 2,
//Abdul Samad Khan
//Step1
//setting default first_name and last_name
//Splitting the input char arr into first_name and last_name
//printing first value of first_name and last-name
//Step2
//instantiating the seating arrangement using row and column
//Assigning guest to a empty seat
//Checking if row and column selected exist inside the boundary
//printing the seating arrangement
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
	char last_name[30];
	char first_name[30];
};
struct auditorium_seating {
	struct guest **seating;
};
int rowNum=0, columnNum=0;
void guest_init_default(struct guest *g)
{
	//assigning default ??? value to last_name and first_name
	strcpy_s(g->first_name,sizeof(g->first_name), "???");
	strcpy_s(g->last_name, sizeof(g->last_name), "???");
}
void guest_init(struct guest *g, char *info)
{
	char *token,*token1;
	//sperating first_name and last_name from the user input i.e info
		token1 = strtok_s(info, "/",&token);
		strcpy_s(g->first_name,sizeof(g->first_name), token1);
		token=strtok_s(NULL, "/", &token);
		strcpy_s(g->last_name, sizeof(g->last_name), token);
	
}
void guest_to_string(struct guest *g)
{
	//printing first value from the char arr of first_name and last_name
	printf("%c.", g->first_name[0]);
	printf("%c.", g->last_name[0]);
}
void auditorium_seating_init(int rowNum, int columnNum, struct auditorium_seating *a)
{
	//instantiating column memory of a->seating
	a->seating = malloc(rowNum  *sizeof(a->seating));

	
	for (int i = 0; i < rowNum; i++) {
		//instantiating row memory of a->seating
		a->seating[i] = malloc(columnNum * sizeof(**a->seating));
		for (int j = 0; j < columnNum; j++) {
		//calling guest_init_default to intialize the array
			guest_init_default(&a->seating[i][j]);
		
		}
	
	}

}
int assign_guest_at(int row, int col, struct auditorium_seating *a, struct guest* g)
{
	//checking if the required seat is empty or filled
	if ((strcmp(a->seating[row][col].first_name, "???") == 0) && (strcmp(a->seating[row][col].last_name, "???") == 0))
	{
		//assigning guest type to the empty seat
		a->seating[row][col] = *g;
		return 1;
	}
	else
	{
		
		return 0;
	}
}
int check_boundaries(int row, int col, struct auditorium_seating *a)
{
	//Checking if the reuired seat exist in the seating arrangement or not
	if (row >= 0 && col >= 0 && (col < columnNum) && (row < rowNum)) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void auditorium_seating_to_string(struct auditorium_seating *a)
{
	
	printf("\nThe current seating  \n-----------------\n");
	//printing the seating arrangement
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < columnNum; j++) {
			
			guest_to_string(&a->seating[i][j]);
			printf(" ");

		}
		printf("\n");
	}


}
void main() {
	struct auditorium_seating auditorium_seating;
 	struct guest temp_guest;
	int row, col;
	char guest_info[30];
	
	// Ask a user to enter a number of rows for an auditorium seating
	printf("Please enter a number of rows for an auditorium seating.\n");
	scanf_s("%d", &rowNum);
	// Ask a user to enter a number of columns for an auditorium seating
	printf("Please enter a number of columns for an auditorium seating.\n");
	scanf_s("%d", &columnNum);
	/*** reading a guest's information ***/
	auditorium_seating_init(rowNum, columnNum, &auditorium_seating);
	printf("Please enter a guest information or enter \"Q\" to quit.\n");
	/*** reading a guest's information ***/
	scanf_s("%s", guest_info, sizeof(guest_info));
	//scanf("%s", guest_info);
	/* we will read line by line **/
	
	while (strcmp(guest_info, "Q") != 0) {
		
		printf("\nA guest information is read.\n");
		// printing information.
		printf("%s", guest_info);
		// guest
		guest_init(&temp_guest, &guest_info);
		// Ask a user to decide where to seat a guest by asking
		// for row and column of a seat
		printf("\nPlease enter a row number where the guest wants to sit.\n");
		scanf_s("%d", &row);
		printf("\nPlease enter a column number where the guest wants to sit.\n");
		scanf_s("%d", &col);
		// Checking if the row number and column number are valid
		// (exist in the theatre that we created.)
		if (check_boundaries(row, col, &auditorium_seating) == 0) {
			printf("\nrow or column number is not valid.\n");
			printf("\nA guest %s %s is not assigned a seat.\n", temp_guest.first_name, temp_guest.last_name);
		}
		else {
			//Assigning a seat for a guest
			if (assign_guest_at(row, col, &auditorium_seating, &temp_guest) == 1) {
			printf("\nThe seat at row %d and column %d is assigned to the guest \n", row, col);
			guest_to_string(&temp_guest);
			auditorium_seating_to_string(&auditorium_seating);
			}
			else {
				printf("\nThe seat at row %d and column %d is taken. \n", row, col);
			}
		}
		// Read the next guestInfo
		printf("\nPlease enter a guest information or enter \"Q\" to quit.\n");
		/*** reading a guest's information ***/
		scanf_s("%s", guest_info, sizeof(guest_info));
	}
}
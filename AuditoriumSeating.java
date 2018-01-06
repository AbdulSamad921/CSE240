//Homework1
//Part 2,Step 2
//Classes, Objects, and Arrays
//Abdul Samad Khan
//Five methods are implemented in the following code
//setting default values to each seat 
//Retrieving guestInfo at a particular seat
//Assigning guest to a new seat
//Checking if row and column selected exist inside the boundary
//printing the seating arrangement

public class AuditoriumSeating {

	//2 dimensional array of Guest type
	Guest [][]seating;
	
	//Initializing seats to default type
	public AuditoriumSeating(int rowNum, int columnNum) {
		seating = new Guest[rowNum][columnNum];
		
		for (int i=0;i<rowNum;i++)
		{
			for(int j=0;j<columnNum;j++)
			{
				
				seating[i][j] =new Guest();		
				
			}
		}
	
	}
	//retrieving guest from the given row,col given to the method 
	private Guest getGuestAt(int row, int col) {
		
		Guest requiredGuest=new Guest();
		requiredGuest=seating[row][col];
		return requiredGuest;
		
	} 
	//assigning guest to an empty seat or returning a false statement if the seat is occupied
	public boolean assignGuestAt(int row, int col, Guest tempGuest) 
	{
		if(seating[row][col].firstName == "???")
			{
				seating[row][col].firstName =tempGuest.firstName;
				seating[row][col].lastName =tempGuest.lastName;

				
				return true;
			}
			else
			{
				return false;
			}
		
				
		
	}
	//checking if the given value exists within boundaries of the initialized 2d array
	public boolean checkBoundaries(int row, int col) {
		//checking if value is less then 0 or greater then the assigned value
		if((row < 0 || col < 0)|| (row>seating.length || col > seating[row].length))
			return false;
		else
			return true;
	}
	//printing the seating arrangement
	public String toString( )
	{
		Guest tempGuest =new Guest();
		String seat=new String();
		
		System.out.printf("\nThe current seating  \n-----------------\n");
		
		for(int row=0; row<seating.length;row++)
		{
			for(int col=0; col<seating[row].length;col++)
			
				{
					//getting guestinfo
					tempGuest=getGuestAt(row,col);
					//Concatenating the guest info in a string
					seat=seat+tempGuest.toString()+". ";
				}
				seat=seat+"\n";
		}
		return seat;
	}

}
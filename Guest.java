//Homework1
//Part 2,Step 1
//Classes, Objects, and Arrays
//Abdul Samad Khan
//Five methods are implemented in the following code
//Default constructor with values assigned
//overloaded constructor with first and last name being assigned given values
//Retrieving first name as a string type
//Retrieving last name as a string type
//arranging names according to given format

public class Guest {
	
	public String lastName;
	public String firstName;
	//Constructor method
	public Guest()
	{
		firstName="???";
		lastName="???";
	}
	//overloaded constructor
	public Guest(String guestInfo) 
	{
		String [] tempArray;
		//split the guestInfo from / in the name
		tempArray=guestInfo.split("/");
		//assign first and last name accordingly to firstname lastname variables
		firstName= tempArray[0];
		lastName = tempArray[1];
		
	}
	//method returns String first name
	public String getFirstName()
	{
		return firstName;
	}
	//method returns String last name
	public String getLastName()
	{
		return lastName;
	}
	//storing guest detail according to the given format in string 
	public String toString() {
		String guestName =firstName.charAt(0)+"."+lastName.charAt(0);
		return guestName;
	}
	
	
}

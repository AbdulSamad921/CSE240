
//Homework1
//Part 1
//Primitive Types, Searching, Recursion
//Abdul Samad Khan
//Four methods are implemented in the following code
//intializeArray (sets 1 at Even places in an array and sets 0 at odd places)
//printArray (prints the array)
//selectionSort (sorts the array in descending order)
//factorial (calculate the factorial of a given number and returns the product of all numbers)

public class Homework {

	public static void initializeArray(int [] array) {
		for(int i=0;i<array.length;i++) {
			//taking modulus for finding even number 
			if(i%2==0)
			array[i]=1;
			//if the modulus is not zero its an odd number
			else
			array[i]=0;
		}
	}
	
	public static void printArray(int []array) {
		for(int i=0;i<array.length;i++) {
			//printing last number as it wont require a comma at the end
			if(i==array.length-1) {
				System.out.print(array[i]);
			}
			//for printing rest of the numbers of an array
			else {
				System.out.print(array[i]+", ");
			}
		}
		//going to next line after array has been printed
		System.out.print("\n");
		
	}
	
	public static void selectionSort(int []array) {
		int minIndex=0;
		//loop that runs till the length of the array
		for(int i=0;i<array.length;i++)
		{
			//setting minIndex equal to i as we have to check first number with all of the rest numbers in array 
			minIndex=i;
			//creating another loop this will be used to compare number with the numbers in array
			for(int scan=i;scan<array.length;scan++) {
				//checking if the selected number at place minIndex is smaller then the next number in array 
				if(array[scan]>array[minIndex])
					//if the selected number is smaller than minIndex is set equal to the place of that number 
					minIndex=scan;
			}
			//the greater number is stored in a temporary place
			int temp = array[minIndex];
			//the place of greater number that we found in the list is replaced with the number we were using to compare 
			array[minIndex] = array[i];
			//the greater number is finally stored in the start of the array 
			array[i] = temp;
		}
		
	}
	public static int factorial(int number) {
		int product=1;
		//the following if returns 1 value if the number whose factorial is to be found is 0
		if(number==0) {
			
			return 1;
		}
		
		else {
			//loop that runs from 1 to the value of the input number 
			//taking product with the initialized number in the beginning of the method
			//the process is continued till i becomes equal to the input number
			for(int i=1;i<=number;i++)
			{
				product=i*product;
			}
			
			return product;
		}
	}
	
	public static void main (String [] arg) {
		 int [] a = {3, 5, 6, 8, 12, 13, 16, 17, 18, 20};
		 int [] b = {18, 16, 19, 3 ,14, 6};
		 int [] c = {5, 2, 4, 3, 1};
		 // testing initializeArray
		 printArray(a); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
		 initializeArray(a);
		 printArray(a); // print: 1, 0, 1, 0, 1, 0, 1, 0, 1, 0
		 // testing initializeArray
		 printArray(b); // print: 18, 16, 19, 3 ,14, 6
		 selectionSort (b);
		 printArray(b); // print: 19, 18, 16, 14, 6, 3
		 // testing factorial
		 System.out.println (factorial (5)); //print: 120
		 c[0] = factorial (c[0]);
		 c[1] = factorial (c[2]);
		 printArray(c); // print: 120, 24, 4, 3, 1
		}
}

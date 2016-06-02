/** Refactoring
a) main has now command line parameters. They are checked if they are integers
b) x, y, z are now the variables number1, number2 and result
e) x1, y1 are not used furthermore and ggt is calculated in another function
*/

#include <stdio.h>

// Prototype of function
int calc_ggt(int, int);

int main(int argc, char *argv[])
{
	int number1, number2, result = 0;

	// Read the command line arguments into variables
	if ((sscanf(argv[1], "%d", &number1) != 1)
	   |(sscanf(argv[2], "%d", &number2) != 1))
	{
    // Is executed when failed to read command line arguments
		printf("Sie haben falsche Parameter uebergeben\n Bitt geben Sie 'ggt Zahl1 Zahl2 ein");
		return 1;
	}


	result = calc_ggt(number1,number2);

	// Print result to command line
	printf("ggT zu %i und %i ist %i.\n", number1, number2, result);


	return 0;
}
// Function which calculate ggt
int calc_ggt(int number1, int number2){
	while (number1 != number2)
	{
	    if (number1 > number2)
			{
	        number1 = number1 - number2;
	    }
		else
		{
		    number2 = number2 - number1;
		}
	}
	return number1;
}

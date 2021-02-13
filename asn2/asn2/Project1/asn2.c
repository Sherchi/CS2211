// CS2211a 2020
// Assignment number 2
// Darwin Liao
// 250959696
// dliao7
// 2020/10/01 


#include <stdio.h>
#include <ctype.h>
#include <string.h>


//Asking for which conversion they want.

//Four functions that take in a char to determine which conversion to use. 
//Char given is taken care of "askForOption"

void kmToM(char dir) {
#define SCALE_FACTOR 1000.0f
	float numToConvert;

	if (dir == 'K') {

		printf("Enter Kilometers: ");
		scanf("%f", &numToConvert);
		printf("The Value is %.2f m\n", numToConvert * SCALE_FACTOR);

	}
	if (dir == 'M') {
		printf("Enter Meters: ");
		scanf("%f", &numToConvert);
		printf("The Value is %.3f Km\n", numToConvert / SCALE_FACTOR);

	}
	
}

void lToG(char dir) {
#define SCALE_FACTOR 3.7854f
	float numToConvert;

	if (dir == 'L') {

		printf("Enter Litres: ");
		scanf("%f", &numToConvert);
		printf("The value is %.3f gal\n", numToConvert / SCALE_FACTOR);

	}

	if (dir == 'G') {

		printf("Enter Gallons: ");
		scanf("%f", &numToConvert);
		printf("The value is %.3f L\n", numToConvert * SCALE_FACTOR);

	}

}

void cmToIn(int dir) {
#define SCALE_FACTOR 2.54f
	float numToConvert;

	if (dir == 'C') {

		printf("Enter Cm: ");
		scanf("%f", &numToConvert);
		printf("The value is %.2f Inches\n", numToConvert / SCALE_FACTOR);

	}

	if (dir == 'I') {

		printf("Enter Inches: ");
		scanf("%f", &numToConvert);
		printf("The value is %.2f cm\n", numToConvert * SCALE_FACTOR);
	}

}

void cToF(int dir) {
	float numToConvert;

	if (dir == 'C') {
		printf("Enter Celsius: ");
		scanf("%f", &numToConvert);
		printf("The value is %.1f F\n", ((numToConvert * 9) / 5) + 32);
	}

	if (dir == 'F') {
		printf("Enter Fahrenheit: ");
		scanf("%f", &numToConvert);
		printf("The value is %1.f C\n", ((numToConvert - 32) * 5) / 9);
	}

}



//Asking for Options for Conversion direction.
char askForOption(char opt1, char opt2) {
	char charMode[20];

	do {

		printf("Choice:");

		//clears the buffer and flush so that the user can enter another value if asked again.
		int length, tempInt;
		do {
			if (fgets(charMode, 25, stdin) == NULL) {
				break;
			}

			//makes the last value of the string null until goes through entire string.
			length = strlen(charMode) - 1;
			tempInt = length;
			charMode[length] = '\0';				

		} while (length == 0);	


		//Exit condition
		if ((charMode[0] == opt1 || charMode[0] == opt2) && strlen(charMode) == 1) {					//So I would have put this as the exit condition, but for some reason it didn't work os I am putting it here instead
			break;																						
		}

		printf("Please enter a Valid Value\n");

		//While True
	} while (1);
	
	return charMode[0];


}

//Main
int main() {
	int mode;
	int tempInt = 0;

	//Loops asking for a number after exiting one of the converisons.
	do {

		//Will repeat asking for an option when an invalid option is given.
		do {
			tempInt = 0;
			printf("\nEnter in a corresponding number.\n");
			printf("1. Km to M conversion.\n");
			printf("2. Litre to Gallon conversion (Liquid).\n");
			printf("3. Cm to In.\n");
			printf("4. Celsius to Fahrenheit.\n");
			printf("5. Quit.\n");
			printf("Choice:");
			scanf("%d", &mode);
		
		
			/*
			* 
			*removes characters from input buffer ending with the newline char. This is for scanf. The above function "askForOption" clears the buffer for fgets instead. 
			*	fgets was only working after pressing enter twice due to asking for an input to indicate when the getchar() != '\n' was over, so had to clear the buffer a different way.
			* 
			*/
			while (getchar() != '\n') {									
				tempInt++;

			}

			//Used to check if the value was more than a single char or was alpha
			if (tempInt > 1) {
				printf("That is not a number between 1 to 5\n");
			}

			//Used to check if it gave a numeric answer not listed.
			else if (mode > 5 || mode < 1) {
				printf("That is not a number between 1 to 5\n");
			}

		
		} while (mode > 5 || mode < 1 || tempInt > 0);

		
		//If the user entered in a valid number, ask for which direction they want to convert, then execute the functions.
		if (mode == 1) {
			printf("K: Km to M\n");
			printf("M: M to Km\n");
			kmToM(askForOption('K', 'M'));

		}

		if (mode == 2) {
			printf("L: Litre to Gallon\n");
			printf("G: Gallon to Litre\n");
			lToG(askForOption('L', 'G'));

		}

		if (mode == 3) {
			printf("C: Cm to Inches\n");
			printf("I: Inches to Cm\n");
			cmToIn(askForOption('C', 'I'));

		}

		if (mode == 4) {
			printf("C: Celsius to Fahrenheit\n");
			printf("F: Fahrenheit to C\n");
			cToF(askForOption('C', 'F'));
		}

	} while (mode != 5);

	printf("\nGoodbye!\n");

}
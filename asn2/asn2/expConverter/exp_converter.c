// CS2211a 2020
// Assignment number 2
// Darwin Liao
// 250959696
// dliao7
// 2020/10/01 


#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Function for calculating the exponent. 
//Repeats until the exponenet is 1 and it ends up being the base value multiplied exponent times.

float calculate(float base, int expo) {

	if (expo == 0) {
		return 1.00;
	}

	if (expo == 1) {
		return base;
	}

	if (expo > 0) {
		if (expo % 2 == 0) {
			return (calculate(base, expo / 2) * calculate(base, expo / 2));

		}
		if (expo % 2 == 1) {
			return (calculate(base, (expo - 1) / 2) * calculate(base, (expo - 1) / 2) * base);
		}
	}
	if (expo < 0) {
		return(1 / calculate(base, -expo));

	}
	
}

//Clears input buffer
void clearStream() {
	while (getchar() != '\n');
}

int main() {

	float base;
	int expo;

	//Asks for Base and exponenet values, assuming no incorrent inputs.
	do {

		printf("Enter in the Base value: ");
		scanf("%f", &base);

		//Exits the loop early if 0 is entered as the base.
		if (base == 0) {
			break;
		}
		clearStream();

		printf("Enter in the Exponent: ");
		scanf("%d", &expo);

		clearStream();

		printf("\nThe value is: %.2f\n", calculate(base, expo));

	} while (1);

	printf("Goodbye!");

}
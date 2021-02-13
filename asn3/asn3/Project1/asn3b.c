// CS2211a 2020
// Assignment number 3
// Darwin Liao
// 250959696
// dliao7
// 2020/10/15
#include <stdio.h>
int main() {
	//Initilization
	int total, input, trueFalse;
	//While True
	while (1) {
		total = 0;
		//Asks for an Input
		printf("Input: ");
		/*
		* reads the input and If the input is 0 then exit the program.
		*	Should have been a do-while loop with input==0 as the exit condition.
		*/
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		//Goes from 1 to inputted value
		for (int numToAdd = 1; numToAdd <= input; numToAdd++) {
			//resets value of the number to False/0
			trueFalse = 0;
			//goes through the first number starting at 2
			for (int multiple = 2; multiple <= numToAdd; multiple++) {
				//For every value between the first multiple of the numToAdd to the second multiple of numToAdd, add that number to the total
				if (numToAdd % multiple == 0) {
					trueFalse++;
				}	
				// Checks if the next multiple has been reached or not/ if the condition has been met.
				if (trueFalse == 1) {
					total = total + numToAdd;
				}
			}
		}
		printf("The final total is: %d\n", total);
	}
	return 0;
}
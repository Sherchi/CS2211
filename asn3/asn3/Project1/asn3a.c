// CS2211a 2020
// Assignment number 3
// Darwin Liao
// 250959696
// dliao7
// 2020/10/15
#include <stdio.h>

int main() {



	int array[] = { 12,63,44,89,3,55,73,27,37,18,234,22,1,4,5};
	int arraySize = sizeof(array);
	const int arrayLength = arraySize / sizeof(int);

	printf("Size of the array is: %d bytes\n", arraySize);
	printf("Length of the array is: %d elements \n", arrayLength);
	printf("\n");
	printf("Part 1 \n");
	printf("The Elements in the array are: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}


	printf("\n\n");
	printf("Part 2 \n");
	printf("The Elements in the array in reverse are: \n");
	for (int i = arrayLength - 1; i >= 0; i--) {
		printf("%d ", array[i]);
	}

	printf("\n\n");
	printf("Part 3 \n");
	printf("The Smallest Element in the array is: \n");


	int smallest = array[0];
	int location = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (array[i] < smallest) {
			smallest = array[i];
			location = i;
		}
	}
	printf("%d at position %d from the left.", smallest, location + 1);
	
	printf("\n\n");
	printf("Part 4 \n");
	printf("The sum (total) of the array is: \n");

	int sum = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (i != arrayLength - 1) {
			printf("%d + ", array[i]);
		}
		else {
			printf("%d", array[i]);
		}

		sum += array[i];
	}

	printf(" equals: %d", sum);

	printf("\n\n");
	printf("Part 5 \n");
	printf("Copy Array into a new array, but in reverse order \n");


	int newArray[arrayLength];
	int newArraySize = sizeof(newArray);
	int newArrayLength = newArraySize / sizeof(int);


	printf("The Original Array: \n");
	for (int i = arrayLength - 1; i >= 0; i--) {
		printf("%d ", array[arrayLength -1 - i]);
		newArray[arrayLength - 1 - i] = array[i];

	}

	printf("\nThe New (Reversed) Array: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", newArray[i]);
	}

	printf("\n\n");
	printf("Part 6 \n");
	printf("The First and Last elements are Switched\n");

	printf("Old Array is: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	
	int tempInt = array[arrayLength - 1];
	array[arrayLength - 1] = array[0];
	array[0] = tempInt;

	printf("\nNew Array is: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}


	printf("\n\n");
	printf("Part 7 \n");
	printf("Sort the Array in Ascending Order\n");
	printf("Original Order: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}

	/*
	* 
	*	Goes through the array and checks if the number is smaller than all 
	*		the previous numbers, if it is, bring it forwards in the array and move
	*		the rest of values up an index.
	*/
	int currentNum, prevNumIndex;
	for (int i = 0; i < arrayLength; i++) {
		currentNum = array[i];
		prevNumIndex = i - 1;

		while (prevNumIndex >= 0 && array[prevNumIndex] > currentNum) {
			array[prevNumIndex + 1] = array[prevNumIndex];
			prevNumIndex--;

		} 

		array[prevNumIndex + 1] = currentNum;

	}
	printf("\nNew Order: \n");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}




	return 0;
}
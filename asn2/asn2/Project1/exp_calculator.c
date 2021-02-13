// CS2211a 2020
// Assignment number 2
// Darwin Liao
// 250959696
// dliao7
// 2020/10/01 


#include <stdio.h>
#include <ctype.h>
#include <string.h>

float calculate(float base,int expo) {

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

int main() {
	printf("%.2f", calculate(2, 2));
	

}
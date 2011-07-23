#include <iostream>
#include "Helper.h"
using namespace std;

int fact[10];

int factorion(int num) {
	int sum = 0;
	for(; num > 0; num /= 10)
		sum += fact[(num % 10)];
	return sum;
}

int main() {
	int total = 0;
	
	//Compute !1 through !9 and store
	for(int i = 0; i < 10; i++)
		fact[i] = Helper::factorial(i);
	
	//Find factorions from 3 to 7*9!
	for(int i = 3; i <= 2540160; i++) {
		if(i == factorion(i))
			total += i;
	}

	cout << total << endl;
	return 0;
}

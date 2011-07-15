#include <iostream>
#include "Helper.h"
using namespace std;

int formula(int a, int b, int n) {
	return ((n * n) + (a * n) + b);
}

int main() {
	int most = 0;
	int ansA = 0;
	int ansB = 0;
	bool end = false;
	
	for(int a = 999; a >= -999; a--) {
		for(int b = 999; b >= 2; b--) { //b must be prime
			if(Helper::isPrime(b)) {
				end = false;
				for(int n = 0; !end; n++) {
					if(!Helper::isPrime(formula(a, b, n))) {
						if(n > most) {
							most = n;
							ansA = a;
							ansB = b;
						}
						end = true;
					}
				}
			}
		}
	}
	cout << ansA << " * " << ansB << " = " << ansA * ansB << " with " << most << " primes." << endl;
	return 0;
}

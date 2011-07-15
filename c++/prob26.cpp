//Code works in VS2008 if all headers and source files are included
//Original code found at http://blog.mycila.com/2009/05/project-euler-problem-26.html
#include <iostream>
#include "BigIntegerLibrary.hh"
#include "Helper.h"
using namespace std;

BigInteger pow(BigInteger base, BigInteger exp) {
	for (BigInteger i = 0; i < exp; i++)
		base *= exp;
	return base;
}

int main() {
	BigInteger ten = 10;
	BigInteger cycle = 142857;
	int res = 7;
	int maxCycleLength = 6;
	BigInteger remainder;

	//for each prime, starting at the maximum possible value (999 and 008 are not primes)
	for(int p = 997; p > 7; p -= 2) {
		if(Helper::isPrime(p)) {
			//if p is prime, we check the smallest number that satisfies 10^i % p = 1
			for(int i = 1; i < p; i++) {
				remainder = modexp(ten, i, p);
				if(remainder == 1) {		 //we found the length i of the cycle of 1/p
					if(maxCycleLength < i) { //we save these values if the current cycle is greater
						maxCycleLength = i;
						res = p;
						cycle = pow(ten, i); //the cycle of 1/p
					}
					break;
				}
			}
		}
	}
	cout << res << endl;
	//system("pause");
}
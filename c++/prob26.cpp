//Original code found at http://blog.mycila.com/2009/05/project-euler-problem-26.html
//To compile:
	//g++ -W -Wall -o prob26 prob26.cpp Helper.cpp -lgmpxx -lgmp
#include <iostream>
#include <gmpxx.h>
#include "Helper.h"
using namespace std;

int main() {
	int ten = 10;
	int res = 7;
	int maxCycleLength = 6;
	mpz_class cycle = 142857;
	mpz_class remainder;

	for(int p = 997; p > 7; p -= 2) { //for each prime, starting at the maximum possible value (999 and 008 are not primes)
		if(Helper::isPrime(p)) {
			for(int i = 1; i < p; i++) { //if p is prime, we check the smallest number that satisfies 10^i % p = 1
				mpz_powm_ui(remainder.mpz_class::get_mpz_t(), mpz_class(ten).mpz_class::get_mpz_t(), i, mpz_class(p).mpz_class::get_mpz_t());
				if(remainder == 1) {		 //we found the length i of the cycle of 1/p
					if(maxCycleLength < i) { //we save these values if the current cycle is greater
						maxCycleLength = i;
						res = p;
						mpz_pow_ui(cycle.mpz_class::get_mpz_t(), mpz_class(ten).mpz_class::get_mpz_t(), i); //the cycle of 1/p
					}
					break;
				}
			}
		}
	}
	cout << res << endl;
}

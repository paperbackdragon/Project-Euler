//To compile:
	//g++ -W -Wall -o prob29 prob29.cpp -lgmpxx -lgmp
#include <iostream>
#include <set>
#include <gmpxx.h>
using namespace std;

int main() {
	set<mpz_class> terms;
	mpz_class curTerm;

	for(int a = 2; a <= 100; a++) {
		for(int b = 2; b <= 100; b++) {
			mpz_pow_ui(curTerm.mpz_class::get_mpz_t(), mpz_class(a).mpz_class::get_mpz_t(), b);
			terms.insert(curTerm);
		}
	}
	
	cout << terms.size() << endl;
	return 0;
}

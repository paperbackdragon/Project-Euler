#ifndef HELPER_H_
#define HELPER_H_

class Helper {
private:
	Helper() {}
public:
	/*Reduces given fraction to smallest values
	NOTE: Fractions must be < 1 */
	static int* reduce(int*);

	/*Finds the sum of the divisors of an integer*/
	static int sumOfDivs(int);
	
	/*Returns true if given integer is prime*/
	static bool isPrime(int);
};

#endif

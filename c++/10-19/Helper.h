#ifndef HELPER_H_
#define HELPER_H_

class Helper {
private:
    Helper() {}
public:
    /* Converts given integer to a string */
    static std::string convertInt(int);
	
	/* Returns the number of digits in given integer*/
	static int numDigits(int);
	
    /* Computes the factorial of an integer */
    static int factorial(int);

    /* Reduces given fraction to smallest values
    NOTE: Fractions must be < 1 */
    static int* reduce(int*);

    /* Finds the sum of the divisors of an integer */
    static int sumOfDivs(int);

    /* Returns true if given integer is prime */
    static bool isPrime(int);
	
	/* Returns true if given string is a palindrome */
	static bool isPalindrome(std::string);
};

#endif

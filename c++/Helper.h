#ifndef HELPER_H_
#define HELPER_H_

class Helper {
private:
    Helper() {}
public:
    /* Converts given integer to a string */
    static std::string convertInt(int);
	
    /* Converts given string to an integer */
    static long long convertStr(std::string);
    
	/* Returns the number of digits in given integer */
	static int numDigits(int);
    
    /* Concatenates integers in given array
    NOTE: Second argument is size of array */
    static int concat(int[], int);
	
    /* Computes the factorial of an integer */
    static int factorial(int);

    /* Reduces given fraction to smallest values
    NOTE: Fractions must be < 1 */
    static int* reduce(int*);

    /* Finds the sum of the divisors of an integer */
    static int sumOfDivs(int);

    /* Returns true if given integer is prime */
    static bool isPrime(int);
    
    /* Returns true if given integer is pandigital
    NOTE: Second argument is largest digit of pandigital
    NOTE: Does not check for digits used more than once */
    static bool isPandigital(int, int);
	
	/* Returns true if given string is a palindrome */
	static bool isPalindrome(std::string);
};

#endif

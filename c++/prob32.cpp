/* URL: http://projecteuler.net/index.php?section=problems&id=32

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Answer: 45228 */

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int numDigits(int num) {
	int digits = 0;
	if(num < 0)
		num = -num;
	while(num > 0) {
		digits++;
		num /= 10;
	}
	return digits;
}

/* Does not check for digits used more than once */
bool isPan(int a, int b, int c) {
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 0;
	int sum = 0;
	//find digits of all 3 numbers
	for(i = 0; a > 0; i++) {
		ary[(a % 10)- 1] = 0;
		a /= 10;
	}
	for(i = 0; b > 0; i++) {
		ary[(b % 10)- 1] = 0;
		b /= 10;
	}
	for(i = 0; c > 0; i++) {
		ary[(c % 10)- 1] = 0;
		c /= 10;
	}
	//check if all are 0
	for(i = 0; i < 9; i++)
		sum += ary[i];
	if(sum == 0)
		return true;
	else
		return false;
}

int main() {
    int a = 0; 			//multiplicand
	int b = 0; 			//multiplier
	int c = 0; 			//product
	set<int> products; 	//set to hold answers
	set<int>::iterator it;
    int total = 0;		//sum of answers
	//while there are 9 digits being considered
	while(numDigits(a) + numDigits(b) + numDigits(c) <= 9) {
        c++;
		int root = (int) sqrt((double)c);
		for(int i = root; i >= 1; i--) {
			if(c % i == 0) {
				a = i;
				b = c / i;
			}
		    if(isPan(a, b, c))	    //if identity is 1-9 pandigital
			    products.insert(c);	//add answer to set
        }
	}
	//sum contents of set and print to cout
	for (it = products.begin(); it != products.end(); it++)
		total += *it;
	cout << total << endl;
    return 0;
}


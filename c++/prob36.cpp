/* URL: http://projecteuler.net/index.php?section=problems&id=36
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
Answer: ? */

#include <iostream>
#include <string>
#include "Helper.h"
using namespace std;

string toBinary(int num) {
	string bi = "";
	for(; num > 0; num /= 2) {
		if(num % 2 == 0)
			bi.insert(bi.begin(), '0');
		else
			bi.insert(bi.begin(), '1');
	}
	return bi;
}

int main() {
	int total = 0;
    for(int i = 1; i < 1000000; i++) {
		string str = Helper::convertInt(i);
		if(Helper::isPalindrome(str)) {
			if(Helper::isPalindrome(toBinary(i)))
				total += i;
		}
	}
	cout << total << endl;
    return 0;
}

/* URL: http://projecteuler.net/index.php?section=problems&id=7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

Answer: 104743 */

#include <iostream>
#include <cmath>
#include "Helper.h"
using namespace std;

int main() {
    int num = 0;
    int count = 0;

    for(int i = 2; count < 10001; i++) {
        if(Helper::isPrime(i)) {
            count++;
            num = i;
        }
    }
	
    cout << num << endl;
    return 0;
}


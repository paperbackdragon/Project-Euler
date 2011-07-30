/* URL: http://projecteuler.net/index.php?section=problems&id=41
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?
Answer: 7652413 */

#include <iostream>
#include <algorithm>
#include "Helper.h"
using namespace std;

int main() {
    int curInt = 0;
    bool found = false;
    int ary[] = {7,6,5,4,3,2,1};
    //pandigital primes are 4 or 7 digits
    do {
        curInt = Helper::concat(ary, 7);
        if(Helper::isPrime(curInt)) {
            found = true;
            cout << curInt << endl;
        }
    } while(found == false && prev_permutation(ary, ary + 7));
    return 0;
}

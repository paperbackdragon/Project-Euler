/* URL: http://projecteuler.net/index.php?section=problems&id=3
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
Answer: 6857 */

#include <iostream>
#include <cmath>
#include "Helper.h"
using namespace std;

int main() {
    int largest = 0;
    long long num = 600851475143LL;
    int root = sqrt(num) + 1;
    for(int i = root; i >= 2; i--) {
        if(num % i == 0) {
            int factor = num / i;
            if(Helper::isPrime(factor)) {
                if (factor > largest)
                    largest = factor;
            }
            if(Helper::isPrime(i)) {
                if (i > largest)
                    largest = i;
            }
        }
    }
    cout << largest << endl;
    return 0;
}


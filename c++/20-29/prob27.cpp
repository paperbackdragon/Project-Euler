/* URL: http://projecteuler.net/index.php?section=problems&id=27
Euler published the remarkable quadratic formula: n^2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
Using computers, the incredible formula  n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, -79 and 1601, is -126479.
Considering quadratics of the form:
    n^2 + an + b, where |a| < 1000 and |b| < 1000
    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |-4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
Answer: -59231 */

#include <iostream>
#include "Helper.h"
using namespace std;

int formula(int a, int b, int n) {
    return ((n * n) + (a * n) + b);
}

int main() {
    int most = 0;
    int ansA = 0;
    int ansB = 0;
    bool end = false;
    for(int a = 999; a >= -999; a--) {
        for(int b = 999; b >= 2; b--) { //b must be prime
            if(Helper::isPrime(b)) {
                end = false;
                for(int n = 0; !end; n++) {
                    if(!Helper::isPrime(formula(a, b, n))) {
                        if(n > most) {
                            most = n;
                            ansA = a;
                            ansB = b;
                        }
                        end = true;
                    }
                }
            }
        }
    }
    cout << ansA * ansB << endl;
    return 0;
}

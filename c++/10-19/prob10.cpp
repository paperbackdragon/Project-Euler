/* URL: http://projecteuler.net/index.php?section=problems&id=10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer: 142913828922 */

#include <iostream>
#include <cmath>
#include "Helper.h"
using namespace std;

int main() {
    long long answer = 0;
    for (long long i = 2; i < 2000000; i++) {
        if (Helper::isPrime(i))
            answer += i;
    }
    cout << answer << endl;
    return 0;
}

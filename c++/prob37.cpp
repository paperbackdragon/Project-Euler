/* URL: http://projecteuler.net/index.php?section=problems&id=37
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
Answer: 748317 */

#include <iostream>
#include <cmath>
#include "Helper.h"
using namespace std;

int main() {
    int firstDig = 0;
    int lastDig = 0;
    int num = 0;
    int total = 0;
    bool prime = false;
    for(int i = 8; i < 999999; i++) {
        prime = false;
        lastDig = i % 10;
        if(lastDig == 2 || lastDig == 3 || lastDig == 5 || lastDig == 7) {
            for(num = i; num > 0; num /= 10)
                firstDig = num;
            if(firstDig == 2 || firstDig == 3 || firstDig == 5 || firstDig == 7) {
                prime = true;
                //check left to right
                for(num = i; num > 0; num %= (int)pow(10, Helper::numDigits(num) - 1)) {
                    if(!Helper::isPrime(num))
                        prime = false;
                }
                if(prime == true) {
                    //check right to left
                    for(num = i; num > 0; num /= 10) {
                        if(!Helper::isPrime(num))
                            prime = false;
                    }
                }
            }
        }
        if(prime)
            total += i;
    }
    cout << total << endl;
    return 0;
}

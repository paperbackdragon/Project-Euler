/* URL: http://projecteuler.net/index.php?section=problems&id=35
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
Answer: 55 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Helper.h"
using namespace std;

int main() {
    int prime = 0;
    int counter = 0;
    vector<int> digits;
    vector<int>::iterator it;
    bool permPrime;
    for(int i = 1; i < 1000000; i++) {
        if(Helper::isPrime(i)) {
            digits.clear();
            //separate digits
            prime = i;
            for(; prime > 0; prime /= 10)
                digits.insert(digits.begin(), prime % 10);
            //check if circular
            permPrime = true;
            while(prime != i) {
                it = digits.begin();
                rotate(digits.begin(), ++it, digits.end());
                //combine digits
                prime = 0;
                for(unsigned int j = 0; j < digits.size(); j++)
                    prime = (prime * 10) + digits[j];
                if(!Helper::isPrime(prime))
                    permPrime = false;
            }
            if(permPrime)
                counter++;
        }
    }
    cout << counter << endl;
    return 0;
}

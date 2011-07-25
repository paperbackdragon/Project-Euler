/* URL: http://projecteuler.net/index.php?section=problems&id=7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743 */

#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int num) {
    if(num == 2)
        return true;

    if(num % 2 == 0)
        return false;

    int root = sqrt(num) + 1;
    for(int i = root; i >= 2; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}


int main() {
    int num = 0;
    int count = 0;

    for(int i = 0; count <= 10001; i++) {
        if(isprime(i)) {
            count++;
            num = i;
        }
    }
    cout << num << endl;
    return 0;
}


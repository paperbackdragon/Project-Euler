/* URL: http://projecteuler.net/index.php?section=problems&id=12

The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

Answer: 76576500 */

#include <iostream>
#include <cmath>
using namespace std;

int numdiv(long num) {
    int divs = 0;
    long root = floor(sqrt(num));
    for(long i = root; i > 0; i--) {
        if(num % i == 0)
            divs += 2;
    }
    return divs;
}

int main() {
    int most = 0;
    int divs = 0;
    long num = 0;
    long tri = 1;
    long i = 1;
    while(most <= 500) {
        divs = numdiv(tri);
        if(divs > most) {
            most = divs;
            num = tri;
        }
        i++;
        tri += i;
    }
    cout << num << endl;
    return 0;
}

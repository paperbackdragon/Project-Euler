/* URL: http://projecteuler.net/index.php?section=problems&id=33
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
Answer: 100 */

#include <iostream>
#include "Helper.h"
using namespace std;

/* If nums share a digit, the OTHER two digits are returned */
double* share(int a, int b) {
    double* p = new double[2];
    if(a%10 == 0 && b%10 == 0) {
        *p = 0;
    } else if((int)a/10 == (int)b/10) {
        *p = a%10;
        *(p+1) = b%10;
    } else if(a%10 == (int)b/10) {
        *p = a/10;
        *(p+1) = b%10;
    } else if((int)a/10 == b%10) {
        *p = a%10;
        *(p+1) = b/10;
    } else if(a%10 == b%10) {
        *p = a/10;
        *(p+1) = b/10;
    } else
        *p = 0;
    return p;
}

int main() {
    double *sh;
    int *ans = new int[2];
    *ans = 1;
    *(ans+1) = 1;
    for(double b = 10; b < 100; b++) {
        for(double a = 10; a < b && a < 100; a++) {
            sh = share((int)a, (int)b);
            if(*sh != 0 && *(sh+1) != 0) {
                if(a / b == *sh / *(sh+1)) {
                    *ans *= (int)a;
                    *(ans+1) *= (int)b;
                }
            }
        }
    }
    ans = Helper::reduce(ans);
    cout << *(ans+1) << endl;
    return 0;
}

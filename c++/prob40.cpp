/* URL: http://projecteuler.net/index.php?section=problems&id=40
An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If d_n represents the nth digit of the fractional part, find the value of the following expression.
d_1 x d_10 x d_100 x d_1000 x d_10000 x d_100000 x d_1000000
(10 + 200 + 3000 + 40000 + 500000 + 456790)
Answer: 210 */

#include <iostream>
#include <cstdlib>
#include "Helper.h"
using namespace std;

int main() {
    int total = 1;
    bool done[] = {false, false, false, false, false, false};
    string digits = "0";
    for(int i = 1; i < 2000000; i++) {
        digits.append(Helper::convertInt(i));
        if(digits.length() >= 1000001 && !done[0]) {
            total *= (int)Helper::convertStr(digits.substr(1000000,1));
            done[0] = true;
        }
        else if(digits.length() >= 100001 && !done[1]) {
            total *= (int)Helper::convertStr(digits.substr(100000,1));
            done[1] = true;
        }
        else if(digits.length() >= 10001 && !done[2]) {
            total *= (int)Helper::convertStr(digits.substr(10000,1));
            done[2] = true;
        }
        else if(digits.length() >= 1001 && !done[3]) {
            total *= (int)Helper::convertStr(digits.substr(1000,1));
            done[3] = true;
        }
        else if(digits.length() >= 101 && !done[4]) {
            total *= (int)Helper::convertStr(digits.substr(100,1));
            done[4] = true;
        }
        else if(digits.length() >= 11 && !done[5]) {
            total *= (int)Helper::convertStr(digits.substr(10,1));
            done[5] = true;
        }
    }
    cout << total << endl;
    return 0;
}

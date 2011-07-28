/* URL: http://projecteuler.net/index.php?section=problems&id=32
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
Answer: 45228 */

#include <iostream>
#include <cmath>
#include <set>
#include "Helper.h"
using namespace std;

int main() {
    int a = 0;              //multiplicand
    int b = 0;              //multiplier
    int c = 0;              //product
    int num = 0;            //pandigital
    set<int> products;      //set to hold answers
    set<int>::iterator it;
    int total = 0;          //sum of answers
    //while there are 9 digits being considered
    while(Helper::numDigits(a) + Helper::numDigits(b) + Helper::numDigits(c) <= 9) {
        c++;
        int root = (int) sqrt((double)c);
        for(int i = root; i >= 1; i--) {
            if(c % i == 0) {
                a = i;
                b = c / i;
            }
            //concatenate
            int nums[] = {a, b, c};
            num = Helper::concat(nums, 3);
            if(Helper::isPandigital(num, 9))//if identity is 1-9 pandigital
                products.insert(c);         //add answer to set
        }
    }
    //sum contents of set and print to cout
    for (it = products.begin(); it != products.end(); it++)
        total += *it;
    cout << total << endl;
    return 0;
}


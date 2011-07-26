/* URL: http://projecteuler.net/index.php?section=problems&id=4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
Answer: 906609 */

#include <iostream>
#include "Helper.h"
using namespace std;

int main() {
    int largest = 0;
    for(int a = 999; a > 0; a--) {
        for(int b = 999; b > 0 && a*b > 999; b--) {
            if(Helper::isPalindrome(a * b)) {
                if((a * b) > largest)
                    largest = a * b;
            }
        }
    }
    cout << largest << endl;
    return 0;
}


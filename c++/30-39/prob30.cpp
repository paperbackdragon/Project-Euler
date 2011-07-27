/* URL: http://projecteuler.net/index.php?section=problems&id=30
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
Answer: 443839 */

#include <iostream>
#include <cmath>
using namespace std;

int sumExpDigits(int num) {
    int sum = 0;
    while(num != 0) {
        sum += (int) pow((double)(num % 10), 5);
        num /= 10;
    }
    return sum;
}

int main() {
    int total = 0;
    for(int i = 2; i <= 295245; i++) {
        if(i == sumExpDigits(i))
            total += i;
    }
    cout << total << endl;
    return 0;
}

/* URL: http://projecteuler.net/index.php?section=problems&id=20
n! means n x (n - 1) x ... x 3 x 2 x 1
For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800, and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!
Answer: 648 */

#include <iostream>
#include <cstdlib>
using namespace std;

string s = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";

int sumDigits(string s) {
    int answer = 0;
    for(unsigned int i = 0; i < s.length(); i++)
        answer += atoi(s.substr(i,1).c_str());
    return answer;
}

int main() {
    cout << sumDigits(s) << endl;
    return 0;
}

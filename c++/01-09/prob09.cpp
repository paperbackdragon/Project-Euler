/* URL: http://projecteuler.net/index.php?section=problems&id=9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
Answer: 31875000 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a = 1;
    int b = 1;
    double c = 1;
    for(a = 1; a < 400; a++) {
        for(b = 1; b < a; b++) {
            c = sqrt(pow(a, 2) + pow(b, 2));
            if(floor(c) == ceil(c) &&  a + b + c == 1000) {
                cout << "a: " << a << endl;
                cout << "b: " << b << endl;
                cout << "c: " << c << endl;
                long long answer = a*b*c;
                cout << answer << endl;
            }
        }
    }
    return 0;
}

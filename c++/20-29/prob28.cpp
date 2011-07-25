/* URL: http://projecteuler.net/index.php?section=problems&id=28
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
Answer: 669171001 */

#include <iostream>
using namespace std;

int main() {
    int size = 3;
    int corner = 1;
    int skip = 1;
    int sum = 1;
    for(int i = 3; size <= 1001; i++) {
        sum += i;
        if(corner == 4) {
            size += 2;
            skip += 2;
            corner = 0;
        }
        i += skip;
        corner++;
    }
    cout << sum << endl;
    return 0;
}

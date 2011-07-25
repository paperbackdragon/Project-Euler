/* URL: http://projecteuler.net/index.php?section=problems&id=5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer: 232792560 */

#include <iostream>
using namespace std;

int main() {
    int answer = 0;
    for(int i = 2520; answer == 0; i += 2520) {
        for(int j = 20; j >= 1; j--) {
            if (i % j != 0) 
                break;
            else if(j == 1) 
                answer = i;
        }
    }
    cout << answer << endl;
    return 0;
}


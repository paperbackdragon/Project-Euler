/* URL: http://projecteuler.net/index.php?section=problems&id=14

The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer: 837799 */

#include <iostream>
using namespace std;

int chain(long long n) {
    int terms = 1;
    while(n > 1) {
        if(n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        terms++;
    }
    return terms;
}

int main() {
    int longest = 0;
    int len = 0;
    long long start = 0;
    for(long long i = 0; i < 1000000; i++) {
        len = chain(i);
        if(len > longest) {
            start = i;
            longest = len;
        }
    }
    cout << start << endl;
    return 0;
}


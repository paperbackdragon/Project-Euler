/* URL: http://projecteuler.net/index.php?section=problems&id=25
The Fibonacci sequence is defined by the recurrence relation:
    Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:
    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the first term in the Fibonacci sequence to contain 1000 digits?
Answer: 4782 */

#include <iostream>
using namespace std;

int term = 3;
float a = 1;
float b = 1;
float c = a + b;
float ap = 0;
float bp = 0;
float cp = 0;

void nextTerms() {
    a = b;
    ap = bp;
    b = c;
    bp = cp;
    if(ap == bp)
        c = a + b;
    else if(bp > ap)
        c = (a * 0.1) + b;
    while(c > 10) {
        c = c * 0.1;
        cp++;
    }
    term++;
}

int main() {
    while(cp + 1 < 1000)
        nextTerms();
    cout << term << endl;
    return 0;
}

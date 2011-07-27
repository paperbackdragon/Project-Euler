/* URL: http://projecteuler.net/index.php?section=problems&id=39
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p <= 1000 is the number of solutions maximised?
Answer: 840 */

#include <iostream>
#include <cmath>
using namespace std;

/* If given integers compute an integral hypotenuse, 
return length of hypotenuse. Otherwise, returns -1. 
NOTE: a and b must be >= 1. */
int isRightTri(int a, int b) {
    double c = 0;
    c = sqrt(pow(a, 2) + pow(b, 2));
    if(c / floor(c) == 1)
        return (int)c;
    else
        return -1;
}

int main() {
    int c = 0;
    int triCount = 0;
    int largest = 0;
    int largeP = 0;
    for(int p = 1000; p >= 4; p--) {
        //Find number of right angle triangles with this perimeter
        triCount = 0;
        for(int a = 1; a < p; a++) {
            for(int b = 1; b < a && b < p; b++) {
                c = isRightTri(a, b);
                if(c > -1) {
                    if(a + b + c == p)
                        triCount++;
                }
            }
        }
        //if this number is > largest, make it largest
        if(triCount > largest) {
            largest = triCount;
            largeP = p;
        }
    }
    cout << largeP << " with " << largest << " solutions." << endl;
    return 0;
}

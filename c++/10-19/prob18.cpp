/* URL: http://projecteuler.net/index.php?section=problems&id=18
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23 [see URL].
That is, 3 + 7 + 4 + 9 = 23.
Find the maximum total from top to bottom of the triangle below.
NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
Answer: 1074 */

#include <iostream>
using namespace std;

int tri [15][15] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
    {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
};

/* Finds largest of 3 and adds to upper num */
int maxsum (int num1, int num2, int up) {
    int biggest = num1;
    if(num2 > biggest)
        biggest = num2;
    return biggest + up;
}

/* Finds largest path */
int path(int num, int tri[][15]) {
    for(int i = num-1; i >= 0; i--) {
        for(int j = 0; j+1 < num && tri[i][j+1] != 0; j++)
            tri[i-1][j] = maxsum(tri[i][j], tri[i][j+1], tri[i-1][j]);
    }
    return tri[0][0];
}

int main() {
    cout << path(15, tri) << endl;
    return 0;
}

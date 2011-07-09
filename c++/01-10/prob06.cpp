#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int sum = 0;
    int square = 0;

    for(int i = 0; i <= 100; i++) {
        sum += pow(i, 2);
        square += i;
    }
    square = pow(square, 2);

    cout << square - sum << endl;

    return 0;
}

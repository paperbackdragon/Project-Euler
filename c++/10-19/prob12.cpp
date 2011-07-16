#include<iostream>
#include<cmath>
using namespace std;

int numdiv(long num) {
    int divs = 0;
    long root = floor(sqrt(num));
    for(long i = root; i > 0; i--) {
        if(num % i == 0)
            divs += 2;
    }
    return divs;
}

int main() {
    int most = 0;
    int divs = 0;
    long num = 0;
    long tri = 1;
    long i = 1;
    while(most <= 500) {
        divs = numdiv(tri);
        if(divs > most) {
            most = divs;
            num = tri;
        }
        i++;
        tri += i;
    }
    cout << num << endl;
    return 0;
}

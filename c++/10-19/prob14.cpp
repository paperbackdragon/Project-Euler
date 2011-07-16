#include<iostream>
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


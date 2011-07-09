#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int num) {
    if(num == 2)
        return true;
    
    if(num % 2 == 0)
        return false;

    int root = sqrt(num) + 1;
    for(int i = root; i >= 2; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int largest = 0;
    long long num = 600851475143LL;
    int root = sqrt(num) + 1;
    for(int i = root; i >= 2; i--) {
        if(num % i == 0) {
            int factor = num / i;

            if(isprime(factor)) {
                if (factor > largest)
                    largest = factor;
            }
            if(isprime(i)) {
                if (i > largest)
                    largest = i;
            }
        }
    }

    cout << largest << endl;

    return 0;
}


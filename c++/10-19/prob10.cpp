#include<iostream>
#include<cmath>
using namespace std;

bool isprime(long long num) {
    if(num == 2)
        return true;
    for(long long i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    long long answer = 0;
    for (long long i = 2; i < 2000000; i++) {
        if (isprime(i)) {
            answer += i;
        }
    }
    cout << answer << endl;
    return 0;
}

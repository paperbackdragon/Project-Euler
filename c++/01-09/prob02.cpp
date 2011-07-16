#include<iostream>
using namespace std;

int main() {
    int answer = 2;
    int a = 1;
    int b = 2;
    int c = a + b;

    while(c < 4000000) {
        if (c % 2 == 0)
            answer += c;
        a = b;
        b = c;
        c = a + b;     
    }
    
    cout << answer << endl;

    return 0;
}


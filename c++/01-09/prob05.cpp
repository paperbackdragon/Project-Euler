#include<iostream>
using namespace std;

int main() {
    int answer = 0;
    
    for(int i = 2520; answer == 0; i += 2520) {
        for(int j = 20; j >= 1; j--) {
            if (i % j != 0) 
                break;
            else if(j == 1) 
                answer = i;
        }
    }

    cout << answer << endl;
    return 0;
}


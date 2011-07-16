#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

string convertInt(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

bool ispalin(int num) {
    string str = convertInt(num);
    stack<char> numStack;
    unsigned int j;

    if(str.length() % 2 == 0) {
        for(int i = 0; i <= ((str.length() - 1) / 2); i++) 
            numStack.push(str.at(i));
        j = str.length() / 2;
    } else {
        for(int i = 0; i <= ((str.length() - 2) / 2); i++)
            numStack.push(str.at(i));
        j = (str.length() / 2) + 1;
    }
    
    for( ; j < str.length(); j++) {
        if(numStack.top() != str.at(j))
            return false;
        numStack.pop();
    }
    return true;
}

int main() {
    int largest = 0;

    for(int a = 999; a > 0; a--) {
        for(int b = 999; b > 0 && a*b > 999; b--) {
            if(ispalin(a * b)) {
                if((a * b) > largest)
                    largest = a * b;
            }
        }
    }
    
    cout << largest << endl;
        
    return 0;
}


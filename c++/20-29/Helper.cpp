#include <cmath>
#include <sstream>
#include <string>
#include <stack>
#include "Helper.h"
using namespace std;

string Helper::convertInt(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int Helper::numDigits(int num) {
    int digits = 0;
    if(num < 0)
        num = -num;
    while(num > 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

int Helper::factorial(int num) {
    if (num > 1)
        return (num * factorial(num - 1));
    else
        return 1;
}

int* Helper::reduce(int* frac) {
    for(int i = *(frac+1); i > 0; i--) {
        if(*frac % i == 0 && *(frac+1) % i == 0) {
            *frac /= i;
            *(frac+1) /= i;
            return frac;
        }
    }
    return 0;
}

int Helper::sumOfDivs(int num) {
    int sum = 0;
    int root = (int) sqrt((double)num);
    for(int i = root; i >= 1; i--) {
        if(num % i == 0) {
            if(i > 1 && (i * i != num))
                sum += i + (num / i);
            else
                sum += i;
        }
    }
    return sum;
}

bool Helper::isPrime(int num) {
    if(num == 2)
        return true;
    if(num % 2 == 0 || num < 2)
        return false;
    int root = (int) sqrt((double)num) + 1;
    for(int i = root; i >= 2; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool Helper::isPalindrome(string str) {
    stack<char> numStack;
    unsigned int j;
	if(str.length() < 1)
		return false;
	else if(str.length() == 1)
		return true;
    else if(str.length() % 2 == 0) {
        for(unsigned int i = 0; i <= ((str.length() - 1) / 2); i++) 
            numStack.push(str.at(i));
        j = str.length() / 2;
    } else {
        for(unsigned int i = 0; i <= ((str.length() - 2) / 2); i++)
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
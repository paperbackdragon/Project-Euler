#include <cmath>
#include "Helper.h"
using namespace std;

int Helper::sumOfDivs(int num) {
	int sum = 0;
	int root = (int) sqrt(num);
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
    
    if(num % 2 == 0)
        return false;

    int root = (int) sqrt(num) + 1;
    for(int i = root; i >= 2; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}

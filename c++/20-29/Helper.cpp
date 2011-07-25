#include <cmath>
#include "Helper.h"
using namespace std;

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

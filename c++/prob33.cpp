#include <iostream>
#include "Helper.h"
using namespace std;

/*If nums share a digit, the OTHER two digits are returned*/
double* share(int a, int b) {
	double* p = new double[2];
	
	if(a%10 == 0 && b%10 == 0) {
		*p = 0;
	} else if((int)a/10 == (int)b/10) {
		*p = a%10;
		*(p+1) = b%10;
	} else if(a%10 == (int)b/10) {
		*p = a/10;
		*(p+1) = b%10;
	} else if((int)a/10 == b%10) {
		*p = a%10;
		*(p+1) = b/10;
	} else if(a%10 == b%10) {
		*p = a/10;
		*(p+1) = b/10;
	} else
		*p = 0;
		
	return p;
}

int main() {
	double *sh;
	int *ans = new int[2];
	*ans = 1;
	*(ans+1) = 1;

	for(double b = 10; b < 100; b++) {
		for(double a = 10; a < b && a < 100; a++) {
			sh = share((int)a, (int)b);
			if(*sh != 0 && *(sh+1) != 0) {
				if(a / b == *sh / *(sh+1)) {
					*ans *= (int)a;
					*(ans+1) *= (int)b;
				}
			}
		}
	}
	
	ans = Helper::reduce(ans);
	cout << *(ans+1) << endl;
	
	return 0;
}

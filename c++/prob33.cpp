#include <iostream>
#include "Helper.h"
using namespace std;

/*If nums share a digit, the OTHER two digits are returned*/
int* share(int a, int b) {
	int* p = new int[2];
	
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

//DOES NOT WORK (is not in main either)
int* canReduce(int a, int b, int *sh) {
	int* p = new int[2];
	
	if(a / *sh == b / *(sh+1))
		p = sh;
	else
		*p = 0;
		
	return p;
}

int main() {
	int *p, *sh;
	int frac[2];

	for(int b = 10; b < 100; b++) {
		for(int a = 10; a < b && a < 100; a++) {
			sh = share(a, b);
			if(*sh != 0) {
				frac[0] = a;
				frac[1] = b;
				p = Helper::reduce(frac);
				if(a == 49 && b == 98)
					cout << *p << " " << *(p+1) << endl;
				if(p != 0) {
					if (*p == *sh && *(p+1) == *(sh+1))
						cout << a << "/" << b << " = " << *p << "/" << *(p+1) << endl;
				}
			}
		}
	}
	
	return 0;
}

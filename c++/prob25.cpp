#include <iostream>
using namespace std;

int term = 3;

float a = 1;
float b = 1;
float c = a + b;

float ap = 0;
float bp = 0;
float cp = 0;

void nextTerms() {
	a = b;
	ap = bp;
	
    b = c;
	bp = cp;
	
	if(ap == bp)
		c = a + b;
	else if(bp > ap)
		c = (a * 0.1) + b;
	
	while(c > 10) {
		c = c * 0.1;
		cp++;
	}
	term++;
}

int main() {
	while(cp + 1 < 1000)
		nextTerms();
		
	cout << term << endl;
			
	return 0;
}

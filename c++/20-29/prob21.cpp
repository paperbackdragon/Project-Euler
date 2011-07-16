#include <iostream>
#include "Helper.h"
using namespace std;

int main() {
	int curSum = 0;
	int total = 0;
	for(int i = 1; i < 10000; i++) {
		curSum = Helper::sumOfDivs(i);
		if(i != curSum && i == Helper::sumOfDivs(curSum))
			total += i;
	}
	cout << total << endl;
	return 0;
}

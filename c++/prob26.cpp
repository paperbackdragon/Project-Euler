#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Helper.h"
using namespace std;

/*Returns true if 1/prime has repeating cycle of prime-1 */
bool hasCycle(int prime) {
	double num = 1 / prime;
	vector<int> cycle;
	bool cycleFound
	bool answer = false;
	
	num *= 10;
	while(num != ceil(num))	{//check each digit
		if(cycle.empty()) {
			if((int)num != cycle.begin())
				cycle.push_back((int)num);
		}
		else {
			
		}
		num -= (int)num;
		num *= 10;
	}
}

int main() {
	for(int i = 0; i < 1000; i++) {
		if(Helper::isPrime(i)) {
			if(hasCycle(prime)
				cout << (pow(10,i) - 1) / i << endl; //digits in cycle
		}
	}
	
	return 0;
}

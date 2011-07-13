#include<iostream>
#include<cmath>
using namespace std;

//Find proper divisors, then sum
int d(int num) {
	int sum = 0;
	int root = sqrt(num);
	for(int i = root; i >= 1; i--) {
		if(num % i == 0) {
			if(i > 1)
				sum += i + (num / i);
			else
				sum += i;
		}
	}
	return sum;
}

int main() {
	int curSum = 0;
	int total = 0;
	for(int i = 1; i < 10000; i++) {
		curSum = d(i);
		if(i != curSum && i == d(curSum))
			total += i;
	}
	cout << total << endl;
	return 0;
}

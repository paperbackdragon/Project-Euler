#include <iostream>
#include <cmath>
using namespace std;

int sumExpDigits(int num) {
	int sum = 0;
	while(num != 0) {
		sum += (int) pow((double)(num % 10), 5);
		num /= 10;
	}
	return sum;
}

int main() {
	int total = 0;
	for(int i = 2; i <= 295245; i++) {
		if(i == sumExpDigits(i))
			total += i;
	}
	cout << total << endl;
	return 0;
}

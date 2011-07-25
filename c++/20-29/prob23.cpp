/* URL: http://projecteuler.net/index.php?section=problems&id=23

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Answer: 4179871 */

#include <iostream>
#include <vector>
#include "Helper.h"
using namespace std;

bool isAbundant(int num) {
	return Helper::sumOfDivs(num) > num;
}

int main() {
	//make list of abundant nums
	vector<int> abundants;
	for(int i = 1; i <= 28123; i++) {
		if(isAbundant(i))
			abundants.push_back(i);
	}
	//make list of nums under 28123
	int nums[28123];
	for(int i = 0; i < 28123; i++)
		nums[i] = i+1;
	//find sums of abundant numbers
	int sum = 0;
	for(unsigned int i = 0; i < abundants.size(); i++) {
		for(unsigned int j = 0; j < abundants.size() && i >= j; j++) {
			sum = abundants[i] + abundants[j];
			if(sum <= 28123) //delete sums from list of all nums
				nums[sum-1] = 0;
		}
	}
	//sum list of all nums
	int total = 0;
	for(int i = 0; i < 28123; i++)
		total += nums[i];
	cout << total << endl;
	return 0;
}

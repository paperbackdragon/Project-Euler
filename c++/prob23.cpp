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

#include <iostream>
#include <vector>
#include <algorithm>
#include "Helper.h"
using namespace std;

int main() {
    int prime = 0;
    int counter = 0;
    vector<int> digits;
    bool permPrime;

	for(int i = 0; i < 1000000; i++) {
        if(Helper::isPrime(i)) {
            //separate digits
            prime = i;
            for(; prime > 0; prime /= 10)
                digits.push_back(prime % 10);
            //check if circular
            permPrime = true;
            while(next_permutation(digits.front(), digits.back())) {
                //combine digits
                prime = 0;
                for(int j = 0; j < digits.size(); j++)
                    prime = (prime * 10) + digits[j];
                if(!Helper::isPrime(prime))
                    permPrime = false;
            }
            if(permPrime)
                counter++;

        }
    }
    cout << counter << endl;
	return 0;
}

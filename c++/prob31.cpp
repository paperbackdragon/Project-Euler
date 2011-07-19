#include <iostream>
#include <cstdlib>
using namespace std;

int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};

/*Amounts entered must be in pence.*/
int combinations(int amount, int size) {
	int comboCount = 0;
	
	if(amount > 0) {
		if(size >= 0 && amount >= coin[size])
			comboCount += combinations(amount - coin[size], size);
		if(size > 0) //don't do if size is 0
			comboCount += combinations(amount, size-1);
	} else if(amount == 0)
		comboCount++;

	return comboCount;
}

int combos(int amount) {
	int i = 0;
	//get largest coin that fits
	for(i = 7; coin[i] > amount && i >= 0; i--); 
	return combinations(amount, i);
}

int main() {
	cout << "Answer: " << combos(200) << endl;
	return 0;
}

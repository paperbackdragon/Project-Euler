#include <iostream>
using namespace std;

int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};

int combos(int amount) {
	static combos = 0;
	//Find largest coin < amount
	//Steadily find smaller denominations for each coin
	return combos;
}

int main() {
	cout << combos(200) << endl;
	return 0;
}

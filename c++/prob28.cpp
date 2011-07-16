#include <iostream>
using namespace std;

int main() {
	int size = 3;
	int corner = 1;
	int skip = 1;
	int sum = 1;
	
	for(int i = 3; size <= 1001; i++) {
		sum += i;
		if(corner == 4) {
			size += 2;
			skip += 2;
			corner = 0;
		}
		i += skip;
		corner++;
	}
	
	cout << sum << endl;
		
	return 0;
}

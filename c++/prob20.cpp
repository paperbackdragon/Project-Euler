#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;

/*Variable 'n' must not be less than 0*/
long long factorial(int n) {//CANNOT BE LONG LONG! FIX!
	if(n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n-1);
}

int sumDigits(string s) {
	int answer = 0;
	for(unsigned int i = 0; i < s.length(); i++) {
		answer += atoi(s.substr(i,1).c_str());
		//cout << answer << endl;
	}
	return answer;
}

int main() {
	stringstream ss;
	string fact;
	ss << factorial(100);
	ss >> fact;
	cout << fact << endl;
	
	cout << sumDigits(fact) << endl;
	return 0;
}

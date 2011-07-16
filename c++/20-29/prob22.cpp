#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool strCmp(string x, string y) {
	if(x.compare(y) < 0)
		return true;
	else
		return false;
}

int getScore(string s) {
	int score = 0;
	for(unsigned int i = 0; i < s.length(); i++)
		score += (((int) s.at(i)) - 64);
	return score;
}

int getTotalScore(vector<string> names) {
	int total = 0;
	for(unsigned int i = 0; i < names.size(); i++)
		total += (getScore(names[i]) * (i+1));
	return total;
}

int main() {
	vector<string> names;
	ifstream namesFile("names.txt");
	
	char curChar;
	string curName = "";
	
	//get names from file
	if(namesFile.is_open()) {
		while(!namesFile.eof()) {
			curChar = namesFile.get();
			
			if(isalpha(curChar))
				curName.push_back(curChar);
			else {
				if(!curName.empty()) {//store finished name
					names.push_back(curName);
					curName.clear();
				}
			}
		}
	}
	namesFile.close();
	
	//alphabetize
	sort(names.begin(), names.end(), strCmp);
	
	//count up name scores
	cout << getTotalScore(names) << endl;
	return 0;
}

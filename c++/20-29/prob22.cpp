/* URL: http://projecteuler.net/index.php?section=problems&id=22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?
Answer: 871198282 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

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
                if(!curName.empty()) {
                    //store finished name
                    names.push_back(curName);
                    curName.clear();
                }
            }
        }
    }
    namesFile.close();
    //alphabetize
    sort(names.begin(), names.end());
    //count up name scores
    cout << getTotalScore(names) << endl;
    return 0;
}

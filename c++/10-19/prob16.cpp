#include<iostream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main() {
    stringstream ss;
    string num = "";
    int answer = 0;

    ss.setf(ios::fixed);
    ss << setprecision(0) << pow(2, 1000);
    ss >> num;
    for(unsigned int i = 0; i < num.length(); i++)
        answer += atoi(num.substr(i,1).c_str());
    
    cout << answer << endl;
    return 0;
}

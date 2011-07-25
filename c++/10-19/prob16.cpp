/* URL: http://projecteuler.net/index.php?section=problems&id=16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
Answer: 1366 */

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstdlib>
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

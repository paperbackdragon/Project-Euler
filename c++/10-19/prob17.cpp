/* URL: http://projecteuler.net/index.php?section=problems&id=17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Answer: 21124 */

#include <iostream>
using namespace std;

int ones(int num) {
    int lets = 0;
    if (num == 1 || num == 2 || num == 6)
        lets = 3;
    else if (num == 4 || num == 5 || num == 9)
        lets = 4;
    else if (num == 3 || num == 7 || num == 8)
        lets = 5;
    return lets;
}

int tens(int num) {
    int lets = 0;
    if(num < 20) {
        if (num == 10)
            lets = 3;
        else if (num == 11 || num == 12)
            lets = 6;
        else if (num == 15 || num == 16)
            lets = 7;
        else if (num == 13 || num == 14 || num == 18 || num == 19)
            lets = 8;
        else if (num == 17)
            lets = 9;
    } else {
        lets = 5;                       //40, 50, 60
        if (num % 10 > 0)
            lets += ones(num % 10);
        if (num >= 20 && num <= 39)     //20, 30
            lets++;
        else if (num >= 80 && num <= 99)//80, 90
            lets++;
        else if (num >= 70 && num <= 79)//70
            lets += 2;
    }
    return lets;
}

int letters(int num) {
    int lets = 0;
    int count = 0;
    int number = num;
    for(; number > 0; count++, number /= 10);
    switch(count) {
        case 1:
            lets = ones(num);
            break;
        case 2:
            lets = tens(num);
            break;
        case 3:
            if(num % 100 == 0)
                lets = ones(num / 100) + 7;
            else if (num % 100 < 10)
                lets = ones(num / 100) + 10 + ones(num % 100);
            else
                lets = ones(num / 100) + 10 + tens(num % 100);
            break;
        case 4:
            lets = 11;
            break;
    }
    return lets;   
}

int main() {
    long answer = 0;
    for(int i = 1; i <= 1000; i++) {
        answer += letters(i);
    }
    cout << answer << endl;
    return 0;
}

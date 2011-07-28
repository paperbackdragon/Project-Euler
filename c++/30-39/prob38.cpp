/* URL: http://projecteuler.net/index.php?section=problems&id=38
Take the number 192 and multiply it by each of 1, 2, and 3:
    192 x 1 = 192
    192 x 2 = 384
    192 x 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).
The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
Answer: 932718654 */

#include <iostream>
#include "../Helper.h"
using namespace std;

/* size is current size of ary */
int* copyAddOne(int* ary, int size) {
    int* temp = ary;
    ary = new int[size + 1];
    for(int i = 0; i < size; i++)
        *(ary + i) = *(temp + i);
    delete[] temp;  //Memory leak? delete[] doesn't work...
    return ary;
}

int main() {
    int pan = 0;    //current pandigital
    int count = 0;  //next number to multiply by
    int* nums;      //array of products
    int largest = 0;//largest pandigital
    for(int i = 1; i < 9876; i++) {
        pan = 0;
        nums = NULL;
        for(count = 0; Helper::numDigits(pan) < 9; count++) {
            nums = copyAddOne(nums, count);
            *(nums + count) = i * (count + 1);
            pan = Helper::concat(nums, count + 1);
            if(Helper::numDigits(pan) == 9 && Helper::isPandigital(pan, 9)) {
                if(pan > largest)
                    largest = pan;
            }
        }
    }
    cout << largest << endl;
    return 0;
}

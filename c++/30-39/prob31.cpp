/* URL: http://projecteuler.net/index.php?section=problems&id=31
In England the currency is made up of pounds and pence and there are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, 1 pound (100p) and 2 pounds (200p).
It is possible to make 2 pounds in the following way:
    1 x 1 pound + 1 x 50p + 2 x 20p + 1 x 5p + 1 x 2p + 3 x 1p
How many different ways can 2 pounds be made using any number of coins?
Answer: 73682 */

#include <iostream>
#include <cstdlib>
using namespace std;

int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};

/* Amounts entered must be in pence. */
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

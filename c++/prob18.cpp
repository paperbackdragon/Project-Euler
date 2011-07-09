#include<iostream>
using namespace std;

int tri [120] = {
    75,
    95, 64,
    17, 47, 82,
    18, 35, 87, 10,
    20, 4, 82, 47, 65,
    19, 1, 23, 75, 3, 34
    88, 2, 77, 73, 7, 63, 67,
    99, 65, 4, 28, 6, 16, 70, 92,
    41, 41, 26, 56, 83, 40, 80, 70, 33,
    41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
    53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
    70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
    91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
    63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
    4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
};

int smalltri [4][4] = {
    3, 0, 0, 0,
    7, 4, 0, 0,
    2, 4, 6, 0,
    8, 5, 9, 3
};

//finds largest of 3 and adds to upper num
int maxsum (int num1, int num2, int num3, int up) {
    int biggest = num1;
    if(num2 > biggest)
        biggest = num2;
    if(num3 > biggest)
        biggest = num3;
    return biggest + up;
}

//finds largest path
int path(int num, int[] tri) {
    for(int i = num; i >= 0; i--) {
        for(int j = 0; j < num; i++) {
            
        }
    }
}

int main() {
    
    return 0;
}

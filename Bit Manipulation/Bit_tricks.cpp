// Shortcuts for playing with bits.

#include<bits/stdc++.h>
using namespace std;

int main(){

    // Check number of set bits in given number
    cout << __builtin_popcount(5) << endl;


    // Make ith Bit set in given number num1.       1 0 0
    int num1 = 4,i = 1; //                       OR 0 1 0
    cout << (num1 | (1 << i)) << endl; //           -----
                                       //           1 1 0

    // Make ith Bit unset in given number num2.     1 1 1
    int num2 = 7; //                            AND   0 1  <= ~(1 0)
    i = 1; //                                       -----
    cout << (num2 & (~(1 << i))) << endl; //        1 0 1


    // Toggle ith Bit of given number num3.         1 1 1
    int num3 = 7; //                            XOR 0 1 0  
    i = 1; //                                       -----
    cout << (num2 ^ (1 << i)) << endl; //           1 0 1

    return 0;
}
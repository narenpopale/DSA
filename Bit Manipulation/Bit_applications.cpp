// Applications of Bit Manipulation

#include<bits/stdc++.h>
using namespace std;

int main(){

    // Divide or Multiply given number with 2
    int num1 = 4;
    cout << (num1 << 1) << endl; // << - Multiply by 2
    cout << (num1 >> 1) << endl; // >> - Divide by 2

    
    // Upper Case to Lower Case conversion or vice versa
    // 5th bit of upper case letter is unset
    // 5th bit of lower case letter is set

    // Lower to Upper case --> make 5th bit unset 
    char ch = 'z';
    cout << (char)(ch & (~(1 << 5))) << endl;

    // Upper to Lower case --> make 5th bit set 
    ch = 'Z';
    cout << (char)(ch | (1 << 5)) << endl;


    // Clear all L.S.B till ith Bit                         1 1 1 - 7
    int num2 = 7; //                                      & 1 1 0 - ~((1 << (i + 1)) - 1)
    int i = 0;    //                                        -----
    cout << (num2 & (~((1 << (i + 1)) - 1))) << endl; //    1 1 0


    // Check if n is power of 2                             1 0 0 0 - 8 = n
    int n = 8; //                                         & 0 1 1 1 - 7 = n - 1
    if((n & (n - 1)) == 0){ //                              -------
        cout << "Power of 2" << endl; //                    0 0 0 0 - 0
    }
    else{
        cout << "Not power of 2" << endl; 
    }


    // XOR application
    // Swap 2 numbers
    int a = 4,b = 6;

    a = a ^ b;  //              a = 1 0 0 ^ 1 1 0 = 0 1 0
    b = b ^ a;  //              b = 1 1 0 ^ 0 1 0 = 1 0 0 = 4
    a = a ^ b;  //              a = 0 1 0 ^ 1 0 0 = 1 1 0 = 6

    cout << a << " " << b << endl;

    return 0;
}
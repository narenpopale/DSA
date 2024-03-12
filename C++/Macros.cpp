#include<bits/stdc++.h>
using namespace std;


// Macro - a piece of code in a program that is replaced by value of macro before compiling the program (not use space)
#define PI 3.14


// Global Variable - Bad Practice! (global scope)
int score = 0;


// Inline Function - it is used when function has only one line of body
// Before compilation, function call gets replaced by body of a function
// No need of extra memory and making function call
inline int getMax(int &a,int &b) {
    return a > b ? a : b;
}


// Default argument - it is optional
// when argument is passed then it consider that otherwise it consider default value
// Make default argument from right to left
int print(int arr[], int n, int start = 0) {
    for(int i = start;i < n; i++) {
        cout << arr[i] << endl;
    }
}


int main() {



    return 0;
}
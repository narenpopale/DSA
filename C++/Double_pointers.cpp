#include<bits/stdc++.h>
using namespace std;


int main() {

    int i = 5;

    // Single Pointer
    int *ptr1 = &i;
    
    // Double Pointer
    int **ptr2 = &ptr1;

    // Prints same value which is in i
    cout << i << endl;
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;


    // Prints same address of i
    cout << &i << endl;
    cout << ptr1 << endl;
    cout << *ptr2 << endl;

    return 0;
}
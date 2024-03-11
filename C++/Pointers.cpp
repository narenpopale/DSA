#include<bits/stdc++.h>
using namespace std;


int main() {

    // SYMBOL TABLE - it is a data structure maintained by compiler which stores the mapping between variables and addresses of memory

    // address of operator (&)
    int num = 0;

    // Format of address is hexadecimal code
    cout << "address of num is " << &num << endl;

    // Pointers - it stores the address
    // ptr is a pointer to int
    int *ptr = &num;
    // or
    // int *ptr = 0;
    // ptr = &num;

    // dereference operator (*) - it goes to the address which are in the pointer and prints the value
    cout << *ptr << endl;

    // size of pointer is 4 or 8 bytes
    cout << sizeof(ptr) << endl;


    cout << "Before Increment : " << num << endl;
    (*ptr)++;
    cout << "After Increment : " << num << endl;


    // Copying of a pointer 
    int *newptr = ptr;
    cout << ptr << " - " << newptr << endl;
    cout << *ptr << " - " << *newptr << endl;


    // pointer arithmatic
    int i = 0;
    int *t = &i;

    cout << "Before Increment address is : " << t << endl;
    t++; // It goes to the next location
    cout << "After Increment address is : " << t << endl;

    return 0;
}
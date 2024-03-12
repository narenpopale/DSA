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



    // Pointers with arrays
    int arr[10] = {1, 2, 3, 4};

    // Both prints the same address
    cout << "address of first memory block is " << arr << endl;
    cout << "address of first memory block is " << &arr[0] << endl;

    // Both prints the same value
    cout << "value of first memory block is " << *arr << endl;
    cout << "value of first memory block is " << arr[0] << endl;


    cout << "value of second memory block is " << *(arr + 1) << endl;


    // arr[i] => access value internally in the form of *(arr + i)


    // Difference between arrays and pointers
    int temp[10] = {1, 2, 3};

    int *q = &temp[0];

    // 1) size difference - 
    cout << "size of temp array is " << sizeof(temp) << endl; // OP - 40
    cout << "size of q pointer is " << sizeof(q) << endl; // OP - 4

    // 2) address difference - 
    cout << "address of temp array is " << &temp[0] << endl; 
    cout << "address of q pointer is " << &q << endl; 

    // 2) Symbol Table entries cannot get changed
    // temp = temp + 1; --> Gives Error (here address of temp is changing)
    // q = q + 1; --> Works fine (here value of q is changing)


    // cout implements differently for char arrays
    int nums[5] = {1, 2, 3, 4, 5};
    char chars[6] = "hello";

    cout << nums << endl; // prints address of first memory block
    cout << chars << endl; // prints entire value

    char *c = &chars[0];
    cout << c << endl; // prints entire value
    cout << *c << endl; // prints value present at address


    // Important
    char ch = 'z';
    char *cptr = &ch;
    // It will prints the value until it will not get null character '\0'
    cout << cptr << endl;


    // Behind the Scene -> below statment gets executed in 2 steps. firstly all content gets into the temp memory and then str gets allocated a memory and all the content of the temp memory gets copied to the str memory
    char str[6] = "abcde";

    // Behind the Scene -> firstly all content gets into the temp memory and then one block is created for s and the address of first memory block of temp memory gets stored in s. (RISKY - Don't use it)
    char *s = "abcde";

    return 0;
}
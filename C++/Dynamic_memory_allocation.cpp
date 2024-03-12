#include<bits/stdc++.h>
using namespace std;


// Pass by value - only data gets copied to the variable
int func1(int n) {
    n++;
    return n;
}


// Pass by reference - address gets passed to the variable
int func2(int &n) {
    n++;
    return n;
}


// Return by reference - bad practice!
int& func3(int n) {
    int &num = n;
    return num;
}


int main() {

    int i = 5;

    // Reference variable - same memory different names
    int &j = i;


    // Static memory allocation - memory gets allocated in stack memory
    int a = 10;

    // Dynamic memory allocation - memory gets allocated in heap memory
    // new char; -> new keyword is used to create dynamic memory in the heap and this statement returns the address of the block of memory which gets created
    char *ch = new char;

    // array created in heap memory
    int *arr = new int[10];


    // Difference between in static and dynamic memory allocation
    // 1. In stack, memory automatically gets released
    // 1. In heap, we have to release memory manually
    // 2. stack memory < heap memory


    // Release memory in Heap - use (delete) keyword
    delete ch;
    delete []arr; 


    // 2d array creation in heap
    int **mat = new int*[5];

    for (int i = 0; i < 5; i++)
    {
        mat[i] = new int[5];
    }    

    // Release 2d array memory in heap
    for (int i = 0; i < 5; i++)
    {
        delete [] mat[i];
    }    
    delete []mat;

    return 0;
}
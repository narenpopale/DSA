#include<bits/stdc++.h>
using namespace std;


void updateArray(int arr[], int n) {

    arr[0] = 120;

}


int main() {
    // Declaration
    int arr[3];

    // Initialization
    arr[1] = 1;

    // Declaration and Initialization
    int nums[4] = {1, 2, 3, 4};

    // Intialize all values with 0
    int zeros[5] = {0};

    // Intialize all values with any values other than 0
    int val[5];
    fill_n(val, 5, 2);


    // when you pass an int array to a function, you are actually passing a pointer to the 
    // array's first element. This means that any modifications made to the array inside the 
    // function will affect the original array in the calling function.
    int values[5] = {1, 2, 3, 4, 5};

    cout << "Before passing to the function value is " << endl;
    cout << values[0] << endl;

    updateArray(values, 5);

    cout << "After passing to the function value is " << endl;
    cout << values[0] << endl;

    return 0;
}
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


    // character array - at the end of strings null character '\0' automaticaly gets added and shows end of the string
    char chars[10] = { 'a', 'b', 'c', 'd' };

    // Inputing the char array
    // cin >> chars;

    // Printing the string 
    cout << chars << endl;

    // cin - when space, tab or enter will get press then cin will stops the execution

    // strings - this is the class which is implemented by character array
    string str = "hello";

    cout << str << endl;


    // 2D arrays = In memory 1d arrays gets created and all the elements of 2d array gets stored in 1d array by this formula (col * i + j)

    // Initializing
    int mat1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int mat2[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9}};

    // Printing
    cout << mat1[0][0] << endl;

    return 0;
}
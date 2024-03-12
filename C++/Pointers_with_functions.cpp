#include<bits/stdc++.h>
using namespace std;

void print(int *p) {
    cout << *p << endl;
}

void update(int *p) {
    // p = p + 1;
    *p = *p + 1;
}

// In functions whole array is not get passed, only pointer for that array is passed
int getSum(int arr[], int n) {

    cout << "size of array in getSum is " << sizeof(arr) << endl;

    int sum = 0;
    for(int i = 0;i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    
    int value = 5;
    int *p = &value;

    print(p);

    // Both prints same address
    cout << "Before update : " << p << endl;
    update(p);
    cout << "After update : " << p << endl;

    // Both prints different value
    cout << "Before update : " << *p << endl;
    update(p);
    cout << "After update : " << *p << endl;

    
    int arr[5] = {1, 2, 3, 4, 5};
 
    cout << "size of array in main is " << sizeof(arr) << endl;
    getSum(arr, 5);

    return 0;
}
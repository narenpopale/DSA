#include<bits/stdc++.h>
using namespace std;



int main() {

    // 1) ARRAYS
    // Normal Array
    int arr[4] = {1, 2, 3, 4};

    // STL Array - It's get implement by normal array and it is static
    array<int, 4> a = {1, 2, 3, 4};

    // size
    cout << a.size() << endl;

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }



    // 2) VECTOR - Dynamic array
    vector<int> v;

    vector<int> last(v); // all elements of vector v will copied to the last vector

    v.push_back(1); // add element in last
    v.pop_back(); // delete last element

    cout << v.capacity() << endl; // capacity() returns memory allocated to a vector - Every time when new element gets added capacity of vector gets double
    cout << v.size() << endl; // size() returns no. of elements in the vector

    v.clear(); // Size will becomes zero but capacity remains same

    return 0;
}
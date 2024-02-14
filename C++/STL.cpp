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

    cout << v.capacity() << endl; // capacity() returns memory allocated to a vector - Every time when new element gets added capacity of vector becomes double
    cout << v.size() << endl; // size() returns no. of elements in the vector

    v.clear(); // Size will becomes zero but capacity remains same

    cout << v.at(0) << endl; // accessing the element



    // 3) Deque - Double ended queue, we can do operations on both the sides front and back
    deque<int> d;

    d.push_front(1); // push element at first index
    d.push_back(2);  // push element at last index

    d.pop_front();  // pop element at first index
    d.pop_back();   // pop element at last index

    cout << d.at(0) << endl; // accessing the element
    cout << d.front() << endl;  // accessing firt element
    cout << d.back() << endl;   // accessing last element

    cout << d.empty() << endl;   // checking is empty


    return 0;
}
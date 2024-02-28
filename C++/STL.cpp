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

    // cout << v.at(0) << endl; // accessing the element



    // 3) Deque - Double ended queue, we can do operations on both the sides front and back
    // - It gets implemented by multiple static arrays

    deque<int> d;

    d.push_front(1); // push element at first index
    d.push_back(2);  // push element at last index

    d.pop_front();  // pop element at first index
    d.pop_back();   // pop element at last index

    cout << d.at(0) << endl; // accessing the element
    cout << d.front() << endl;  // accessing firt element
    cout << d.back() << endl;   // accessing last element

    cout << d.empty() << endl;   // checking is empty



    // 4) List - we can do operations on both the sides front and back
    // - It gets implemented by doubly linkedlist

    list<int> l; // Declaration
    list<int> ll(5, 100); // Declaration and Initialization

    l.push_front(1); // push element at first index
    l.push_back(2);  // push element at last index

    l.pop_front();  // pop element at first index
    l.pop_back();   // pop element at last index

    cout << l.front() << endl;  // accessing firt element
    cout << l.back() << endl;   // accessing last element

    cout << l.empty() << endl;   // checking is empty


    // for accessing the elements we need to traverse on list
    for(auto i: l) {
        cout << i << endl;
    }



    // 5) Stack - LIFO
    stack<int> s;

    s.push(1); // push into the stack
    s.pop(); // pop from the stack
    s.size(); // size of the stack
    s.empty(); // check if stack empty or not

    cout << s.top() << endl; // accessing top element



    // 6) Queue - FIFO
    queue<int> q;

    q.push(1); // push into the queue
    q.pop(); // pop first element from the queue
    q.size(); // size of the queue
    q.empty(); // check if queue empty or not

    // cout << q.front() << endl; // accessing front element 



    // 7) Priority Queue
    // 1. Max Heap
    priority_queue<int> pq1;

    pq1.push(2); // pushing into pq
    pq1.pop(); // deleting from pq
    pq1.size(); 
    pq1.empty();
    
    // cout << pq1.top() << endl; // Accessing from pq

    // 2. Min Heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(2); // pushing into pq
    pq2.pop(); // deleting from pq
    pq2.size(); 
    pq2.empty();
    
    cout << pq2.top() << endl; // Accessing from pq



    // 8) Set - stores the unique elements
    // behind the scene implemented by BST
    // stores elements in sorted order
    set<int> st;

    st.insert(1); // inserting into set
    st.erase(1); // deleting from set
    st.count(1); // checks element present in set or not
    st.find(1); // return the iterator of given elememt, if element doesn't exist then return st.end()

    // accessing set elements
    for(auto i: st) cout << i << endl; 



    // 9) Map - stores n key value pairs
    // 1. map - implemented by Red Black Tree or Balanced Tree
    // TC of functions is O(logn)
    map<int, string> m;

    // storing elements
    m[1] = "one"; 
    m.insert({2, "two"});

    m.count(1); // checks element present in map or not
    m.find(1); // return the iterator of given elememt, if element doesn't exist then return m.end()

    // 2. unordered map - implemented by Hash Table
    // TC of functions is O(1)
    unordered_map<int, string> um;



    // ALGORITHMS
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(0);

    // Search if 2 present in vector or not
    cout << "binary search : " <<  binary_search(vec.begin(), vec.end(), 1) << endl;

    // Upper Bound
    cout << "Upper Bound : " << upper_bound(vec.begin(), vec.end(), 2) - vec.begin() << endl;

    // Lower Bound
    cout << "Lower Bound : " << lower_bound(vec.begin(), vec.end(), 2) - vec.begin() << endl;


    // Max
    max(12, 20);

    // Min
    min(12, 20);

    // Swap
    int x = 1, y = 2;
    swap(x, y);

    // Reverse
    string str = "hello";
    reverse(str.begin(), str.end());

    return 0;
}
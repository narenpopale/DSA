#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Max Heap
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    cout << "Top : " << pq.top() << endl;

    pq.pop();

    cout << "Size is " << pq.size() << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(4);

    cout << "Top : " << minHeap.top() << endl;

    minHeap.pop();

    cout << "Size is " << minHeap.size() << endl;

    return 0;
}
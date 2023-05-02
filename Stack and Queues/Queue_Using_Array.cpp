#include <iostream>
using namespace std;

const int size = 5;
int front = 0, rear = 0;
int queue[size];

// Push Operation
void push(int x)
{
    if (rear - front == size)
        cout << "Queue is Full" << endl;
    else
        queue[(rear++) % size] = x;
}

// Pop Operation
void pop()
{
    if (rear - front == 0)
        cout << "Queue is Empty" << endl;
    else
        queue[(front++) % size] = -1;
}

// Print all Elements
void print()
{
    for (int i = front; i < rear; i++)
    {
        cout << queue[i % size] << endl;
    }
}

// Get Top element
int Top()
{
    if (rear - front == 0)
        cout << "Queue is Empty" << endl;
    else
        return queue[front % size];
}

// Get Size of Stack
int Size()
{
    return rear - front;
}

// Check Stack is Empty
bool isEmpty()
{
    if (rear - front == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        push(arr[i]);
    }

    cout << "Size of Queue is " << Size() << endl;

    print();

    for (int i = 0; i < n; i++)
    {
        pop();
    }

    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;

    return 0;
}
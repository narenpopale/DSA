#include <iostream>
#include <queue>
using namespace std;

// Stack Using 2 Queues
queue<int> q1, q2;

// Push Operation
void push(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

// Pop Operation
int pop()
{
    int temp = q1.front();
    q1.pop();
    return temp;
}

// Top Operation
int top()
{
    return q1.front();
}

// Check Size of Stack
int size()
{
    return q1.size();
}

// Check Stack is Empty
bool empty()
{
    return q1.empty();
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        push(temp);
    }

    cout << "Stack size is " << size() << endl;

    for (int i = 0; i < n; i++)
    {
        cout << top() << endl;
        pop();
    }

    cout << "Is Stack Empty : " << empty() << endl;

    return 0;
}
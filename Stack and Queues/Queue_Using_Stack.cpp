#include <iostream>
#include <stack>
using namespace std;

// Queue Using 2 Stacks
stack<int> s1, s2;

// Push Operation
void push(int x)
{

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(x);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

// Pop Operation
int pop()
{
    int temp = s1.top();
    s1.pop();
    return temp;
}

// Top Operation
int top()
{
    return s1.top();
}

// Check Queue is Empty
bool empty()
{
    return s1.empty();
}

// Check Size of Queue
int size()
{
    return s1.size();
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

    cout << "Queue size is " << size() << endl;

    for (int i = 0; i < n; i++)
    {
        cout << top() << endl;
        pop();
    }

    cout << "Is Queue Empty : " << empty() << endl;

    return 0;
}
#include <iostream>
using namespace std;

int top = -1;
int stack[1000];

// Push Operation
void push(int x)
{
    stack[++top] = x;
}

// Pop Operation
void pop()
{
    if (top == -1)
        cout << "Stack is Empty" << endl;
    else
        top--;
}

// Get Top element
int Top()
{
    return stack[top];
}

// Get Size of Stack
int size()
{
    return top + 1;
}

// Check Stack is Empty
bool isEmpty()
{
    if (top == -1)
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

    cout << "Size of Stack is " << size() << endl;

    for (int i = 0; i < n; i++)
    {
        cout << Top() << endl;
        pop();
    }

    if (isEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is Not Empty" << endl;

    return 0;
}
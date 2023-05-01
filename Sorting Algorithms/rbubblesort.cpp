// Bubble Sort Using Recursion

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{

    // base case
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[5] = {3, 1, 5, 2, 4};

    int n = 5;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
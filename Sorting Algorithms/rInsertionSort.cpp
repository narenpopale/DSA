// Insertion Sort Using Recursion

#include <iostream>
using namespace std;

void insertionSort(int arr[], int i, int n)
{

    // base case
    if (i == n)
    {
        return;
    }

    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {

        if (arr[j] > temp)
        {
            // shift
            arr[j + 1] = arr[j];
        }
        else
        { // ruk jao
            break;
        }
    }
    // copy temp value
    arr[j + 1] = temp;

    insertionSort(arr, i + 1, n);
}

int main()
{
    int arr[5] = {3, 1, 5, 2, 4};

    int n = 5;

    insertionSort(arr, 1, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
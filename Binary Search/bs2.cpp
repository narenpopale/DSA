// For finding pivot in an sorted and rotated array {7,9,1,2,3} ==> Pivot is 1

#include <iostream>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0,e = n-1;

    int mid = s + (e - s)/2;

    while (s<e)
    {
        if(arr[0] <= arr[mid]){
            s = mid+1;
        }

        if (arr[mid] <= arr[n-1])
        {
            e = mid;
        }

        mid = s + (e - s)/2;
        
    }
    
    cout << arr[s] << endl;

    return 0;
}
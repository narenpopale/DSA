// Search an Element k in a Sorted & Rotated array using Binary Search

#include <iostream>
using namespace std;


// 1) First Approach
int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s,int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int main()
{

    int n, k;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int pivot = getPivot(arr,n);

    if (arr[pivot] <= k && arr[n-1] >= k)
    {
        cout << binarySearch(arr,pivot,n-1,k) <<endl;
    }
    else{
        cout << binarySearch(arr,0,pivot-1,k) <<endl;
    }
    

    return 0;
}



// 2) Second Approach

// int findElement(int arr[],int k,int n){
//     int s = 0,e = n-1;

//     int mid = mid = s + (e-s)/2;

//     while (s<=e)
//     {
//         if (arr[mid] == k)
//         {
//             return mid;
//         }

        //    It means k and mid is on a one line
//         if((k >= arr[0] && arr[mid] >= arr[0]) || (k <= arr[n-1] && arr[mid] <= arr[n-1])){

//             if (arr[mid] < k)
//             {
//                 s = mid + 1;
//             }
//             else{
//                 e = mid - 1;
//             }

//         }
//         else if (k >= arr[0] && arr[mid] <= arr[n-1])  It means k is on a first line and mid is on a second line
//         {
//             e = mid - 1;
//         }
//         else if (arr[mid] >= arr[0] && k <= arr[n-1])  It means k is on a second line and mid is on a first line
//         {
//             s = mid + 1;
//         }
        
//         mid = s + (e-s)/2;
//     }

//     return -1;
    
// }

// int main(){
//     int n, k;

//     cin >> n >> k;

//     int arr[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << findElement(arr,k,n) <<endl;

//     return 0;
// }
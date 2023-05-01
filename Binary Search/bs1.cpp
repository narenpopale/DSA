// For finding first and last occurance of an element and no. of all occurances using binary search

#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t>0)
    {

        int n,first = -1,last = -1;

        cin >> n;

        int k; // k is a element which we want to find in a given array;

        cin >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int s = 0,e = n-1;	

        // for first element
        while (s<=e)
        {
            int mid = (s + e)/2;

            if (arr[mid] == k)
            {
                first = mid;
                e = mid - 1;
            }
            else if (arr[mid] < k)
            {
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }        
            
        }

        s = 0,e = n-1;

        // for last element
        while (s<=e)
        {
            int mid = (s + e)/2;

            if (arr[mid] == k)
            {
                last = mid;
                s = mid + 1;
            }
            else if (arr[mid] < k)
            {
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }        
            
        }
        

        // cout << first <<" "<< last <<endl; for finding first and last element

        // cout << (last - first) + 1 <<endl; for finding no of all elements

        t--;
    }
    


    return 0;
}
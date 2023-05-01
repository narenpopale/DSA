// Find square root of a given number n using binary search.

#include<iostream>
using namespace std;

int findSqrt(int n){
    int s = 0,e = n,ans = 0;

    int mid = s + (e-s)/2;

    while (s<=e)
    {
        if (mid*mid == n)
        {
            return mid; 
        }

        if (mid*mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        
        if (mid*mid > n)
        {
            e = mid - 1;
        }

        mid = s + (e-s)/2;        
    }
    
    return ans;
}

int main(){

    int n = 777;

    cout << findSqrt(n) <<endl;

    return 0;
}
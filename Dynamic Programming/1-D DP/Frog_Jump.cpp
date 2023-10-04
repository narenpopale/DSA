// Link - https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


// Memoization
// TC - O(N)
// SC - O(N) + O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr, vector<int> &dp)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return abs(arr[1] - arr[0]);

    if (dp[n] != -1)
        return dp[n];

    int n1 = abs(arr[n] - arr[n - 1]) + solve(n - 1, arr, dp);
    int n2 = abs(arr[n] - arr[n - 2]) + solve(n - 2, arr, dp);

    return dp[n] = min(n1, n2);
}

int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return solve(n - 1, arr, dp);
}


// Tabulation
// TC - O(N)
// SC - O(N) 

int frogJump(int n, vector<int> &arr)
{
    if(n == 1) return 0;
    vector<int> dp(n);
    
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    
    for(int i = 2; i < n; i++) {
        int n1 = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        int n2 = abs(arr[i] - arr[i - 2]) + dp[i - 2];
        dp[i] = min(n1, n2);
    }
    
    return dp[n - 1];
}
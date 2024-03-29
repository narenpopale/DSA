// Given an array of ‘N’  positive integers, we need to return the maximum sum of the
// subsequence such that no two elements of the subsequence are adjacent elements in the array.


#include <bits/stdc++.h>
using namespace std;



// Memoization
// TC - O(N)
// SC - O(N) + O(N)


int solveUtil(int ind, vector<int> &arr, vector<int> &dp)
{

    if (dp[ind] != -1) return dp[ind];

    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}



// Tabulation
// TC - O(N)
// SC - O(N)


int solveUtil(int n, vector<int> &arr, vector<int> &dp)
{

    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1) pick += dp[i - 2];
        int nonPick = 0 + dp[i - 1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1];
}



// Space Optimization
// TC - O(N)
// SC - O(1)


int solve(int n, vector<int> &arr)
{
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1) pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }

    return prev;
}


int main()
{

    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout << solve(n, arr);
}
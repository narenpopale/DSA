// Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair.
// At a time we can climb either one or two steps.
// We need to return the total number of distinct ways to reach from 0th to Nth stair.


#include <bits/stdc++.h>
using namespace std;

// Tabulation
// TC - O(N)
// SC - O(N)

int main()
{

    int n = 3;
    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}


// Space Optimization
// TC - O(N)
// SC - O(1)

int space_optimization()
{

    int n = 3;

    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }

    cout << prev;

    return 0;
}
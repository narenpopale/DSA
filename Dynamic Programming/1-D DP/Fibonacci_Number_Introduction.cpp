// Introduction of Dynamic Programming

// 2 Types of DP
// - Memoization (Top - Down)
// - Tabulation (Bottom - Up) --> Space Optimization



// Problem - Find Nth Fibonacci Number
// Fibonacci Numbers = 0, 1, 1, 2, 3, 5, 8,.....


#include <bits/stdc++.h>
using namespace std;



// Recursion (Top - Down) 

// TC - O(2^N)
// SC - O(N)

int rec(int n)
{
    // Base Case
    if (n <= 1) return n;

    return rec(n - 1) + rec(n - 2);
}



// Memoization (Top - Down) 
// Better than Recursion

// TC - O(N)
// SC - O(N) + O(N)

int memo(int n, vector<int> &dp)
{
    // Base Case
    if (n <= 1) return n;

    // Step 2 - Check if current sub problem has been previously solved
    if (dp[n] != -1) return dp[n];

    // Step 1 - Store values of Sub Problems into DP Array 
    return dp[n] = memo(n - 1, dp) + memo(n - 2, dp);
}



// Tabulation (Bottom - Up)
// Better than Memoization

// TC - O(N)
// SC - O(N)

int tabu(int n, vector<int> &dp)
{  
    // Step 1 - Initialize Base Cases of Recursion
    dp[0]= 0;
    dp[1]= 1;
    
    // Step 2 - Convert Recurance Relation of Recursion into Tabulation
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }

    return dp[n];
}



// Space Optimization (Bottom - Up)
// Better than Tabulation

// TC - O(N)
// SC - O(1)

int spaceOpti(int n)
{  
    int prev2 = 0;
    int prev1 = 1;
    
    for(int i = 2; i <= n; i++){
        int cur_i = prev2 + prev1;
        prev2 = prev1;
        prev1 = cur_i;
    }

    return prev1;
}



int main()
{
    int n = 5;

    // Step 0 - Initialize DP Array of Sub Problems
    vector<int> dp(n + 1, -1);

    cout << "Recursion : " << rec(n) << endl;
    cout << "Memoization : " << memo(n, dp) << endl;
    cout << "Tabulation : " << tabu(n, dp) << endl;
    cout << "Space Optimization : " << spaceOpti(n) << endl;

    return 0;
}
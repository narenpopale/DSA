// We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix,
// such that there is a minimum cost past that we select.
// At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.



#include <bits/stdc++.h>
using namespace std;



// Memoization
// TC - O(M * N)
// TC - O(M * N) + O((M - 1) + (N - 1))



// Helper function to find the minimum sum path from (i, j) to (0, 0) in the matrix
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0 && j == 0) return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0) return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it


    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);


    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}


// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));   // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}



// Tabulation
// TC - O(M * N)
// TC - O(M * N)



// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else
            {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0) up += dp[i - 1][j]; // Include the minimum path sum from above
                else up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0) left += dp[i][j - 1]; // Include the minimum path sum from the left
                else left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}



// Space Optimization
// TC - O(M * N)
// SC - O(N)



// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else
            {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0) up += prev[j]; // Include the minimum path sum from above (previous row)
                else up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0) left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[m - 1];
}
// https://leetcode.com/problems/candy/description/

// TC - O(N)
// SC - O(2N)


#include <bits/stdc++.h>
using namespace std;


int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1);  // Initialize an array 'left' to store the number of candies given to children from the left.
    vector<int> right(n, 1); // Initialize an array 'right' to store the number of candies given to children from the right.
    int cnt = 1;             // Initialize a counter to keep track of the number of candies given.
    int ans = 0;             // Initialize the answer variable to store the total number of candies needed.

    // Calculate the number of candies given to children from the left side.
    for (int i = 1; i < n; i++)
    {
        if (ratings[i - 1] < ratings[i])
        {
            cnt++; // Increase the counter if the child's rating is higher than the previous child.
        }
        else
        {
            cnt = 1; // Reset the counter to 1 if the child's rating is not higher.
        }

        left[i] = cnt; // Store the number of candies given to the current child in the 'left' array.
    }

    cnt = 1; // Reset the counter for the right side.

    // Calculate the number of candies given to children from the right side.
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            cnt++; // Increase the counter if the child's rating is higher than the next child.
        }
        else
        {
            cnt = 1; // Reset the counter to 1 if the child's rating is not higher.
        }
        
        right[i] = cnt; // Store the number of candies given to the current child in the 'right' array.
    }

    // Calculate the total number of candies needed by taking the maximum of candies from the left and right for each child.
    for (int i = 0; i < n; i++)
    {
        ans += max(left[i], right[i]);
    }

    return ans; // Return the total number of candies needed to meet the requirements.
}
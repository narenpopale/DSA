// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.


// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


// Note - This problem is finding no. of subarrays with sum goal


int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();       // Get the size of the input array
    unordered_map<int, int> m; // Create an unordered map to store cumulative sums and their frequencies
    int sum = 0;               // Initialize a variable to keep track of the cumulative sum
    int ans = 0;               // Initialize the answer variable to count subarrays

    m[0]++; // Initialize the map with a sum of 0 (empty subarray)

    // Iterate through the input array
    for (int i = 0; i < n; i++)
    {
        sum += nums[i]; // Add the current element to the cumulative sum

        // Check if there is a cumulative sum (prefix sum) in the map that matches the desired 'goal'
        if (m.find(sum - goal) != m.end())
        {
            ans += m[sum - goal]; // Increment the answer by the frequency of the matching cumulative sum
        }

        m[sum]++; // Increment the frequency of the current cumulative sum in the map
    }

    return ans; // Return the total count of subarrays with the given sum 'goal'
}
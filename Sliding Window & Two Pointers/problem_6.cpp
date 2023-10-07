// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.


// TC - O(N)
// SC - O(1)


#include <bits/stdc++.h>
using namespace std;


int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();               // Get the size of the input array.
    int odd_cnt = 0, cnt = 0, ans = 0; // Initialize variables to keep track of odd numbers count, temporary count, and the final answer.
    int s = 0, e = 0;                  // Initialize two pointers, s and e, for the sliding window.

    while (e < n)
    { // Loop through the array using the 'e' pointer.
        if (nums[e] % 2 != 0)
            odd_cnt++; // Check if the current element is odd, and if so, increment the odd count.

        if (odd_cnt == k)
        {                // If the required count of odd numbers is reached:
            int num = 0; // Initialize a temporary variable to count subarrays.
            while (odd_cnt == k && s <= e)
            { // Move the 's' pointer to count subarrays satisfying the condition.
                if (nums[s] % 2 != 0)
                    odd_cnt--; // Decrement odd count if 's' points to an odd number.
                num++;         // Increment the subarray count.
                s++;           // Move the 's' pointer.
            }
            cnt = num; // Update the temporary count.
        }

        ans += cnt; // Add the temporary count to the final answer.
        e++;        // Move the 'e' pointer to expand the window.
    }

    return ans; // Return the total count of nice subarrays.
}

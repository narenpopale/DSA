// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums. A subarray is a contiguous non-empty sequence of elements within an array.


// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    stack<pair<int, long long>> s;
    long long minSum = 0, maxSum = 0;

    // Find sum of min for all subarrays
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top().first] > nums[i])
        {
            s.pop();
        }

        long long cnt = s.empty() ? n - i : s.top().first - i;
        long long prevSum = s.empty() ? 0 : s.top().second;

        long long sum = (nums[i] * cnt) + prevSum;

        s.push({i, sum});
        minSum += sum;
    }

    while (!s.empty()) s.pop();

    // Find sum of max for all subarrays
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top().first] < nums[i])
        {
            s.pop();
        }

        long long cnt = s.empty() ? n - i : s.top().first - i;
        long long prevSum = s.empty() ? 0 : s.top().second;

        long long sum = (nums[i] * cnt) + prevSum;

        s.push({i, sum});
        maxSum += sum;
    }

    return maxSum - minSum;
}
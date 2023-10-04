// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.


// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


long long sumSubarrayMins(vector<int> &nums)
{
    int n = nums.size();
    stack<pair<int, long long>> s;
    long long minSum = 0, maxSum = 0;

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

    return minSum;
}
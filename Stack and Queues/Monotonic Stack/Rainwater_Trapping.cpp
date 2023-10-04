// Given n non-negative integers representing an elevation map where the width of each bar is 1
// compute how much water it can trap after raining.


#include <bits/stdc++.h>
using namespace std;


// 1. Approach
// TC - O(3N)
// SC - O(2N)


int trap(vector<int> &arr)
{
    int n = arr.size();
    int prefix[n], suffix[n];

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }

    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }

    int waterTrapped = 0;

    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }

    return waterTrapped;
}


// 2. Approach - Monotonic Stack
// TC - O(2N)
// SC - O(N)


int trap(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            int temp = s.top();
            s.pop();

            if (!s.empty() && arr[s.top()] > arr[temp])
            {
                int num = min(arr[i], arr[s.top()]);
                ans += (num - arr[temp]) * (i - s.top() - 1);
            }

            if (s.empty() || arr[s.top()] < arr[temp])
            {
                s.push(temp);
                break;
            }
        }

        s.push(i);
    }

    return ans;
}


// 3. Approach - Two Pointers
// TC - O(N)
// SC - O(1)


int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }

            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }

            right--;
        }
    }
    
    return res;
}
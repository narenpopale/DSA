// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]).
// return the next greater number for every element in nums.

// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty()) ans[i] = st.top();
        }

        st.push(nums[i % n]);
    }
    
    return ans;
}
// Given an array, for all indices find first greater element in the right. If not found put -1.

// TC - O(N)
// SC - O(N)


#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();
        else ans[i] = -1;

        st.push(nums[i]);
    }

    return ans;
}
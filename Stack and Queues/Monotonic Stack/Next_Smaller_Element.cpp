// Given an array, for all indices find first smaller element in the left. If not found put -1.

// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && st.top() >= A[i]) st.pop();

        if (st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(A[i]);
    }

    return ans;
}
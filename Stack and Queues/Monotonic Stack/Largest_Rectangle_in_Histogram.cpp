// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
// return the area of the largest rectangle in the histogram.


#include <bits/stdc++.h>
using namespace std;


// 1st Approach
// TC - O(2N) + O(2N) + O(N) ~ O(N)
// SC - O(3N)


int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty()) leftsmall[i] = 0;
        else leftsmall[i] = st.top() + 1;

        st.push(i);
    }

    // clear the stack to be re-used
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();

        if (st.empty()) rightsmall[i] = n - 1;
        else rightsmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxA = 0;

    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }

    return maxA;
}


// 2nd Approach - Optimal
// TC - O(2N) ~ O(N)
// SC - O(N)


int largestRectangleArea(vector<int>& arr) {
    int maxA = 0;
    int n = arr.size();
    stack<int> s;

    for(int i = 0;i <= n; i++) {

        while((i == n && !s.empty()) || (!s.empty() && arr[s.top()] > arr[i])) {
            int height = arr[s.top()];
            s.pop();

            int right = i;
            int left = s.size() == 0 ? -1 : s.top();
            int width = right - left - 1;

            maxA = max(maxA, height * width);
        }

        s.push(i);
    }   

    return maxA;
}
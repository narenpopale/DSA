// Given a rows x cols binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.


// TC - O(M * 3N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int> &arr, int n)
{
    int maxA = 0;
    stack<int> s;

    for (int i = 0; i <= n; i++)
    {

        while ((i == n && !s.empty()) || (!s.empty() && arr[s.top()] > arr[i]))
        {
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


int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v(n, 0);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1') v[j] = 1 + v[j];
            else v[j] = 0;
        }
        
        ans = max(ans, largestRectangleArea(v, n));
    }

    return ans;
}
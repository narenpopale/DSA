// Subsets using BitMask
// Given an integer array nums of unique elements, return all possible subsets.
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Approach - BitMasking
// TC - O(2^n) * O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int no_of_sets = 1 << n;

    vector<vector<int>> ans(no_of_sets);

    for (int i = 0; i < no_of_sets; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                ans[i].push_back(nums[j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};

    vector<vector<int>> ans;

    ans = subsets(v);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
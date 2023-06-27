// https://leetcode.com/problems/jump-game/description/

// TC - O(N)
// SC - O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        bool reachable = false;
        int len = 0;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] >= len)
            {
                len = 0;
                reachable = true;
            }
            else
                reachable = false;
            len++;
        }

        return reachable;
    }
};
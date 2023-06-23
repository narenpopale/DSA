//  Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array
//  if you can flip at most k 0's.

// TC - O(N)
// SC - O(K)

#include <bits/stdc++.h>
using namespace std;


int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    queue<int> q;
    int ans = 0;

    for (int s = 0, e = 0; e < n; e++)
    {
        if (nums[e] == 0)
            q.push(e);
        if (q.size() > k)
        {
            s = q.front() + 1;
            q.pop();
        }
        ans = max(ans, e - s + 1);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestOnes(nums, k) << endl;
    return 0;
}

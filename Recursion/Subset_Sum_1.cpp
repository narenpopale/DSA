// Given a list arr of N integers, print sums of all subsets in it.

// TC - O(2^n)
// SC - O(2^n)


    #include<bits/stdc++.h>
    using namespace std;

    void solve(int index, int sum, vector<int>& ans, vector<int> arr, int n){
        
        if(index >= n) {
            ans.push_back(sum);
            return ;
        }
        
        solve(index + 1, sum + arr[index], ans, arr, n);
        solve(index + 1, sum, ans, arr, n);
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0, 0, ans, arr, N);
        return ans;
    }

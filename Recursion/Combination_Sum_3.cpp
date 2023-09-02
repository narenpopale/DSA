// Find all valid and unique combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.


// TC - O(9^k)
// SC - O(x * k)
// x - no. of valid combinations


    void solve(int index, int k, int n, vector<int> temp, vector<vector<int>> &ans){
        if(k <= 0) {
            if(n == 0) ans.push_back(temp);
            return ;
        }

        for(int i = index;i <= 9; i++){
            if(n - i < 0) break;
            temp.push_back(i);
            solve(i + 1, k - 1, n - i, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
      
        solve(1, k, n, temp, ans);
      
        return ans;
    }

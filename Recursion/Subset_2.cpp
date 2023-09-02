// Given an integer array nums that may contain duplicates, return all possible subsets.
// The solution set must not contain duplicate subsets. Return the solution in any order.


// TC - O(2^n * k)
// SC - O(2^n * k)
// k = average length of every subset


      #include <bits/stdc++.h>
      using namespace std;


      void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
        
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
           
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }

      vector < vector < int >> subsetsWithDup(vector < int > & nums) {
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
        
         findSubsets(0, nums, ds, ans);
        
         return ans;
      }

      int main() {
         vector < int > nums = {1,2,2 };
         vector < vector < int >> ans = subsetsWithDup(nums);
         return 0;
      }

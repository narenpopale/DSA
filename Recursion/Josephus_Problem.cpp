// Link - https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

// TC - O(N) + O(N)
// SC - O(N)


    #include<bits/stdc++.h>
    using namespace std;

    int solve(int index, int k, vector<int> v) {
        
        if(v.size() == 1) return v[0];
        
        index = (index + k) % v.size();
        v.erase(v.begin() + index);
        
        return solve(index, k, v);
    }
  
    int safePos(int n, int k) {
        
        vector<int> v;
        
        for(int i = 1;i <= n; i++) v.push_back(i);
        
        return solve(0, k - 1, v);
    }

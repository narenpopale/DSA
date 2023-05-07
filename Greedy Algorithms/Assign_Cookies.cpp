// https://bit.ly/3Wl3PBd

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int n = s.size();
        int m = g.size();

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0,j = 0,ans = 0;

        while(i < n && j < m){
            if(s[i] >= g[j]){
                ans++;
                i++;
                j++;
            }
            else if(s[i] < g[j]) i++;
            else j++;
        }

        return ans;
    }
};
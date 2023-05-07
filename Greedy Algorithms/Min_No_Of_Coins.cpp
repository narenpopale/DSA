// https://bit.ly/3Ka7xYU

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        
        for(int i = 9; i >= 0; i--){
            while(N >= arr[i]){
                ans.push_back(arr[i]);
                N -= arr[i];
            }
        }
        
        return ans;
    }
};
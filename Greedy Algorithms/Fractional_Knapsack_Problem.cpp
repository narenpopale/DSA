// https://bit.ly/3PsqOFL

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        vector<pair<double,int>> v;
        
        for(int i = 0;i < n; i++){
            double cp = arr[i].value/(float)arr[i].weight; 
            v.push_back(make_pair(cp, i));
        }
        
        sort(v.begin(), v.end());
        
        for(int i = n - 1;i >= 0; i--) {
            int index = v[i].second;
            int val = arr[index].value;
            int wet = arr[index].weight;
            
            if(W <= 0) break;
            
            if(wet <= W){
                ans += val;
                W -= wet;
            }
            else{
                ans += (v[i].first * W);
                W = 0;
            }
        }
        
        return ans;
    }
        
};
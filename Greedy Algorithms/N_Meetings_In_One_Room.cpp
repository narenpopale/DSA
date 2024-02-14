// https://bit.ly/3A6Ob1Y

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Solution for sorting it with respect to the start time of the meetings
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = end[i];
            p.second = start[i];
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        int cnt = 1, e = v[0].first;

        for (int i = 1; i < n; i++)
        {
            if (e < v[i].second)
            {
                cnt++;
                e = v[i].first;
            }
        }

        return cnt;
    }


    // Solution for sorting it with respect to the end time of the meetings
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        
        for(int i = 0;i < n; i++ ) {
            v.push_back({end[i], start[i]});
        }
        
        sort(v.begin(), v.end());
        int endTime = v[0].first;
        int ans = 1;
        
        for(int i = 1; i < n; i++) {
            if(endTime < v[i].second) {
                endTime = v[i].first;
                ans++;
            }
        }
        
        return ans;
    }
};
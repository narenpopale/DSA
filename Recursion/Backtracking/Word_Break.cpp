// Given a string s and a dictionary of strings wordDict, return true.
// if s can be segmented into a space-separated sequence of one or more dictionary words.

// TC - O(n*n)
// sC - O(w)
// n = length of string
// w = length of wordDict


#include<bits/stdc++.h>
using namespace std;


bool solve(int index, string s, set<string> &m)
{

    if (index >= s.length()) return true;

    string temp = "";
    for (int i = index; i < s.length(); i++)
    {
        temp += s[i];
        if (m.find(temp) != m.end())
        {
            bool is = solve(i + 1, s, m);
            if (is) return true;
        }
    }

    return false;
}


bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> m;

    for (auto i : wordDict) m.insert(i);

    return solve(0, s, m);
}
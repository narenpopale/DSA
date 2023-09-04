// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.


// TC - O(2^n * n)
// SC - O(n)


#include <bits/stdc++.h>
using namespace std;


bool check(string str)
{
    int s = 0, e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e]) return false;
        s++;
        e--;
    }

    return true;
}

void solve(int index, vector<string> temp, vector<vector<string>> &ans, string s)
{
    if (index >= s.length())
    {
        ans.push_back(temp);
        return;
    }

    string str = "";

    for (int i = index; i < s.length(); i++)
    {
        str += s[i];
        if (!check(str)) continue;

        temp.push_back(str);
        solve(i + 1, temp, ans, s);
        temp.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;

    solve(0, temp, ans, s);
    
    return ans;
}
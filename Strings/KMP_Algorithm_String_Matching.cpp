// Given two strings, one is a text string, txt and other is a pattern string, pat.
// The task is to print the indexes of all the occurences of pattern string in the text string.
// Use one-based indexing while returing the indices.

// Solution - KMP Algorithm

// TC - O(N + M)
// SC - O(M)


#include <bits/stdc++.h>
using namespace std;


// Calculating Longest Prefix and Suffix
void computeLPS(string &pattern, vector<int> &LPS, int m)
{
    LPS[0] = 0;
    int length = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            LPS[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = LPS[length - 1];
            }
            else
            {
                LPS[i] = length;
                i++;
            }
        }
    }

}


vector<int> strStr(string str, string pattern)
{
    int n = str.length();
    int m = pattern.length();
    vector<int> ans;

    vector<int> LPS(m, 0);

    // Computing LPS 
    computeLPS(pattern, LPS, m);

    int i = 0, j = 0;

    // Apply KMP Algo
    while (i < n)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        
        // Pattern Found
        if (j == m)
        {
            ans.push_back(i - m);
            j = LPS[j - 1];
        }
        else if (i < n && str[i] != pattern[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return ans;
}
//  You are given a string s and an integer k.
//  You can choose any character of the string and change it to any other uppercase English character.
//  You can perform this operation at most k times.
//  Return the length of the longest substring containing the same letter you can get after performing the above operations.

//  Solution - https://www.youtube.com/watch?v=gqXU1UyA8pk

// TC - O(N)
// SC - O(26)

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string str, int k)
{

    int n = str.length();
    unordered_map<char, int> m;
    int ans = 0, maxFreq = 0;

    for (int s = 0, e = 0; e < n; e++)
    {
        m[str[e]]++;
        maxFreq = max(maxFreq, m[str[e]]);
        int windowSize = e - s + 1;
        if (windowSize - maxFreq > k)
            m[str[s++]]--;
        ans = max(ans, e - s + 1);
    }

    return ans;
}

int main()
{
    string str = "ABAB";
    int k = 2;
    cout << characterReplacement(str, k) << endl;
    return 0;
}

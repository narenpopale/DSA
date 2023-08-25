
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// Given a string s, return the sum of beauty of all of its substrings.

// TC - O(N*N*26) ~ O(N^2)
// SC - O(26) ~ O(1)


#include <bits/stdc++.h>
using namespace std;


int beautySum(string s)
{
    int n = s.length(), sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        vector<int> count(26, 0);
        count[s[i] - 'a']++;
        
        for (int j = i + 1; j < n; j++)
        {
            count[s[j] - 'a']++;

            int minNum = INT_MAX, maxNum = INT_MIN;

            for (int k = 0; k < 26; k++)
            {
                if (count[k]) minNum = min(minNum, count[k]);
                if (count[k]) maxNum = max(maxNum, count[k]);
            }

            sum = sum + (maxNum - minNum);
        }
    }

    return sum;
}
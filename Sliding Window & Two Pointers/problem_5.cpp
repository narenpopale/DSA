// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.


// TC - O(N)
// SC - O(3)


#include <bits/stdc++.h>
using namespace std;


int numberOfSubstrings(string str)
{
    int n = str.length();       // Get the length of the input string.
    unordered_map<char, int> m; // Create a hash map to store character counts.
    int s = 0, e = 0, ans = 0;  // Initialize pointers and answer variable.

    while (e < n)
    {                // Loop through the string using 'e' pointer.
        m[str[e]]++; // Increment the count of the character at position 'e'.

        // Check if all three characters 'a', 'b', and 'c' are present in the current substring.
        while (m['a'] > 0 && m['b'] > 0 && m['c'] > 0 && s < e)
        {
            ans += n - e; // If all characters are present, add the count of valid substrings.
            m[str[s]]--;  // Decrease the count of the character at position 's'.
            s++;          // Move the 's' pointer to the right to check the next substring.
        }

        e++; // Move the 'e' pointer to the right to expand the substring.
    }

    return ans; // Return the total count of substrings containing 'a', 'b', and 'c'.
}
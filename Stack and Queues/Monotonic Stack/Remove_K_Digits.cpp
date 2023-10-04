// Given string num representing a non-negative integer num, and an integer k, 
// return the smallest possible integer after removing k digits from num.


// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


// Function to reverse a string
string reverse(string str) {
    int s = 0, e = str.length() - 1;
    while (s < e) {
        swap(str[s++], str[e--]);
    }
    return str;
}

// Function to remove k digits from a given number to make it as small as possible
string removeKdigits(string num, int k) {
    int n = num.length();  // Get the length of the input number
    string ans = "";       // Initialize an empty string to store the result
    stack<char> s;         // Use a stack to keep track of the selected digits

    // Loop through each digit in the input number
    for (int i = 0; i < n; i++) {
        // While the stack is not empty, the current digit is smaller than the top of the stack,
        // and there are enough remaining digits to reach the desired length (n - k),
        // pop elements from the stack.
        while (!s.empty() && s.top() > num[i] && s.size() + (n - i) > (n - k)) {
            s.pop();
        }
        // Push the current digit onto the stack.
        s.push(num[i]);
    }

    // After processing all digits, remove any extra digits from the stack to reach the desired length (n - k).
    while (s.size() > (n - k)) {
        s.pop();
    }

    // Build the result string by popping elements from the stack.
    while (s.size() > 0) {
        ans += s.top();
        s.pop();
    }

    // Remove leading zeros from the result.
    for (int i = ans.length() - 1; i >= 0; i--) {
        if (ans[i] == '0') {
            ans.pop_back();
        } else {
            break;
        }
    }

    // Reverse the result string to get the final answer.
    ans = reverse(ans);

    // If the result is empty, return "0"; otherwise, return the result.
    return ans.length() == 0 ? "0" : ans;
}

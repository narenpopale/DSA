// Problem Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// TC - O(k ^ n)
// SC - O(k ^ n)
// n - length of given string
// k - average length of mapped string 


    void solve(int index, string s, vector<string> &ans, string digits, unordered_map<int, string> m){

        if(index >= digits.length()){
            ans.push_back(s);
            return;
        }

        string temp = m[digits[index] - '0'];

        for(auto ch : temp) {
            solve(index + 1, s + ch, ans, digits, m);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        string s = "";

        if(digits.length() == 0) return ans;

        solve(0, s, ans, digits, m);

        return ans;
    }

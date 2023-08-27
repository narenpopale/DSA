// Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

// TC - O(2^n)
// SC - O(n) + O(n)

     #include<bits/stdc++.h>
     using namespace std;

    void solve(int one, int zero, int n, string op, vector<string> &ans) {
        
        if(n == 0) {
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1 += '1';
        solve(one + 1, zero, n - 1, op1, ans);
        
        if(one > zero) {
            string op2 = op;
            op2 += '0';
            solve(one, zero + 1, n - 1, op2, ans);
        }
        
        return; 
    }

  	vector<string> NBitBinary(int N)
  	{ 
  	    vector<string> ans;
  	    solve(0, 0, N, "", ans);
  	    return ans;
  	}

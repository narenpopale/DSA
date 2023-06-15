// Generate all Balanced Parentheses
// Recursion Tree - Input/Output Method


#include <iostream>
#include <vector>
using namespace std;


void solve(int open, int close, string op, vector<string> &ans)
{

    if (open == 0 && close == 0)
    {
        ans.push_back(op);
        return;
    }

    if (open != 0)
    {
        string op1 = op;
        op1 += '(';
        solve(open - 1, close, op1, ans);
    }

    if (close > open)
    {
        string op1 = op;
        op1 += ')';
        solve(open, close - 1, op1, ans);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans;
    string op = "";
    int open = n;
    int close = n;

    solve(open, close, op, ans);

    for (auto i: ans)
    {
        cout << i << " ";
    }    

    return 0;
}
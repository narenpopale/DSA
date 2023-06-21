// Convert Prefix expression to Postfix expression

#include <bits/stdc++.h>

using namespace std;

// The main function to convert Prefix expression
// to Postfix expression
string preToPost(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];
        string str = "";
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            str += st.top();
            st.pop();
            str += st.top();
            st.pop();
        }
        str += ch;
        st.push(str);
    }

    return st.top();
}

int main()
{
    string exp = "*-A/BC-/AKL";
    cout << "Prefix expression: " << exp << endl;
    cout << "Postfix expression: " << preToPost(exp) << endl;
    return 0;
}
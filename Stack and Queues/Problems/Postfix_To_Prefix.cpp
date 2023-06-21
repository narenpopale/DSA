// Convert Postfix expression to Prefix expression

#include <bits/stdc++.h>

using namespace std;

// The main function to convert Postfix expression
// to Prefix expression
string postToPre(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        string str = "";
        char ch = s[i];
        str += ch;

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string c = st.top();
            st.pop();
            str += st.top();
            st.pop();
            str += c;
        }

        st.push(str);
    }

    return st.top();
}

int main()
{
    string exp = "ABC/-AK/L-*";
    cout << "Postfix expression: " << exp << endl;
    cout << "Prefix expression: " << postToPre(exp) << endl;
    return 0;
}
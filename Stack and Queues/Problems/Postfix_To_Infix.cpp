// Convert Postfix expression to Infix expression

#include <bits/stdc++.h>

using namespace std;

// The main function to convert Postfix expression
// to Infix expression
string postToInfix(string s)
{
    int n = s.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        string str = "";

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string c = st.top();
            st.pop();
            str += '(';
            str += st.top();
            st.pop();
            str += ch;
            str += c;
            str += ')';
        }
        else
            str += ch;

        st.push(str);
    }

    return st.top();
}

int main()
{
    string exp = "ABC/-AK/L-*";
    cout << "Postfix expression: " << exp << endl;
    cout << "Infix expression: " << postToInfix(exp) << endl;
    return 0;
}
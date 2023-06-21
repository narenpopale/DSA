// Convert Prefix expression to Infix expression


#include<bits/stdc++.h>

using namespace std;

// The main function to convert Prefix expression
//to Infix expression
string preToInfix(string pre_exp)
{
    stack<string> st;
    int n = pre_exp.size() - 1;
    for (int i = n; i > -1; i--)
    {
        char ch = pre_exp[i];
        if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        {
            string exp = "(" + st.top() + ch;
            st.pop();
            exp += st.top() + ")";
            st.pop();
            st.push(exp);
        }
        else
        {
            string temp = "";
            temp += ch;
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
  string exp = "*-A/BC-/AKL";
  cout << "Prefix expression: " << exp << endl;
  cout << "Infix expression: " << preToInfix(exp) << endl;
  return 0;
}
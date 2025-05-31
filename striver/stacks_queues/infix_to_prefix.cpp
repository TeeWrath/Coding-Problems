#include<bits/stdc++.h>
using namespace std;

int priorityOp(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string postfixExpression(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            ans += c;
        }
        else if (c == ')')
            st.push(')');
        else if (c == '(')
        {
            while (st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // operator
        else
        {
            if (!st.empty() && (priorityOp(c) < priorityOp(st.top())))
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infix2Prefix(string s){
    reverse(s.begin(),s.end());
    string ans = postfixExpression(s);
    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){
    string s;
    cout << "Enter infix expression: ";
    cin >> s;
    cout << "The prefix expression is: " << infix2Prefix(s) << endl;
    return 0;
}
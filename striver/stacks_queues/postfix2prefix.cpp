#include<bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s){
    int i=0; stack<string> st;

    while(i<s.size()){
        // for operand
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            string operand(1,s[i]);
            st.push(operand);
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(s[i] + t2 + t1);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s;
    cout << "Enter postfix expression: ";
    cin >> s;
    cout << "The prefix expression is: " << postfixToPrefix(s) << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s){
    int i= s.size() - 1; stack<string> st;

    while(i >=0){
        // for operand
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            string operand(1,s[i]);
            st.push(operand);
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(t1 + t2 + s[i]);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s;
    cout << "Enter prefix expression: ";
    cin >> s;
    cout << "The postfix expression is: " << prefixToPostfix(s) << endl;
    return 0;
}
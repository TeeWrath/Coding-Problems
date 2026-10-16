#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(auto c :s){
            switch (c){
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ')' :
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                    }
                    else st.push(c);
                    break;
                case ']' :
                    if(!st.empty() &&st.top() == '['){
                        st.pop();
                    }
                    else st.push(c);
                    break;
                case '}' :
                    if(!st.empty() &&st.top() == '{'){
                        st.pop();
                    }
                    else st.push(c);
                    break;
            }
        }

        return st.empty();
    }
};

int main(){
    string s = "[(])";
    cout << Solution().isValid(s) << endl;
    return 0;
}
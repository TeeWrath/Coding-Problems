#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
    
            for(char x:s){
                if(st.empty()){
                    st.push(x);
                }
                else{
                    if(x == ')' && st.top() == '('){
                        st.pop();
                        continue;
                    }
                    else if(x == ']' && st.top() == '['){
                        st.pop();
                        continue;
                    }
                    else if(x == '}' && st.top() == '{'){
                        st.pop();
                        continue;
                    }else{
                        st.push(x);
                    }
                }
            }
    
            return st.size() == 0;
        }
    };
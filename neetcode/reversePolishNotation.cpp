#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;

        for(int i=0;i<n;i++){
            if(tokens[i] == "+"){
                int eval=0;
                while(!st.empty()){
                    eval += stoi(st.top());
                    st.pop();
                }
                st.push(to_string(eval));
            }
            else if(tokens[i] == "-"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                int eval = y-x;
                st.push(to_string(eval));
            }
            else if(tokens[i] == "*"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                int eval = x*y;
                st.push(to_string(eval));
            }
            else if(tokens[i] == "/"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                int eval = y/x;
                st.push(to_string(eval));
            }else st.push(tokens[i]);
        }

        return stoi(st.top());
    }
};

int main(){
    vector<string> tokens = {"1","2","+","3","*","4","-"};
    cout << Solution().evalRPN(tokens) << endl;
    return 0;
}
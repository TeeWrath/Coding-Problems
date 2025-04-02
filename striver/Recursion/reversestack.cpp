#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insert_at_bottom(stack<int> &st, int x){
        if(st.size() == 0){ st.push(x);}
        else{
            int y = st.top();
            st.pop();
            insert_at_bottom(st,x);
            st.push(y);
        }
    }
    void fun(stack<int> &st){
        if(st.size() > 0){
            int x = st.top();
            st.pop();
            
            fun(st);
            
            insert_at_bottom(st,x);
        }
    }
    void Reverse(stack<int> &St){
        fun(St);
    }
};
#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size();
    string ans ="";
    stack<char> st;
    for(int i=0; i<n ; i++){
        while(!st.empty() && k>0 && ((st.top() - '0') > (num[i] - '0'))){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    while(ans.size() != 0 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if(ans.empty()) return "0";
    return ans;
}

int main(){
    string num = "10";
    int k=2;
    string ans = removeKdigits(num,k);
    cout << ans << endl;
    return 0;
}
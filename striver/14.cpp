#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.empty()) return "";
            string prefix = strs[0];
            int pref_len = prefix.size();
    
            for(int i=1; i<strs.size(); i++){
                string s = strs[i];
                while(pref_len > s.size() || prefix != s.substr(0,pref_len)){
                    pref_len--;
                    if(pref_len == 0) return "";
                    prefix = prefix.substr(0,pref_len);
                }
            }
            return prefix;
        }
    };
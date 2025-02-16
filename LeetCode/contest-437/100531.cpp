#include<bits/stdc++.h>
using namespace std;

// Brute force (resolved for each edge case)
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int cnt = 0;
        
        if(s.length() == 1) return true;
        // if(k == 1)
        
        for(int i=0; i<s.length(); i++){
            if(i==0){
                if(k==1){
                    if(s[i+1] != s[i]) return true;
                }
                cnt = 1;
            }
            else if(s[i] != s[i-1]){
                cnt = 1;
                if(cnt == k && (i== s.length() -1 || s[i+1] != s[i])) return true;
            }else if(s[i] == s[i-1]){
                cnt++;
                if(cnt == k && (i== s.length() -1 || s[i+1] != s[i])) return true;
            }
        }
        
        return false;
    }
};
#include<bits/stdc++.h>
using namespace std;

// brute force - very slow and memory heavy
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            map<char,char> mpp = {};
            map<char,char> revMap = {};
            int n = s.size();
    
            for(int i=0; i<n; i++){
                if(mpp.find(s[i]) != mpp.end() && mpp[s[i]] != t[i]) return false;
                else{
                    if(revMap.find(t[i]) != revMap.end() && revMap[t[i]] != s[i]) return false;
                    mpp[s[i]] = t[i];
                    revMap[t[i]] = s[i];
                }
            }
    
            return true;
        }
    };
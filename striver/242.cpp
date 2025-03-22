#include<bits/stdc++.h>
using namespace std;

// TC - O(n) and SC - O(n) if every character can be taken and O(1) if only 26 alphabets are taken
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false;
            int n = s.size();
            map<char,int> mpp = {};
    
            for(int i=0; i<n; i++){
                if(mpp.find(s[i]) == mpp.end()){
                    mpp[s[i]] = 1;
                }
                else{
                    mpp[s[i]]++;
                }
            }
    
            for(int i=0; i<n; i++){
                if(mpp.find(t[i]) == mpp.end()) return false;
                mpp[t[i]]--;
            }
    
            for(auto& it: mpp){
                if(it.second != 0) return false;
            }
    
            return true;
        }
    };
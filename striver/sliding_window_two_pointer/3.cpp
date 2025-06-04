#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int lenMax = 0;
    for(int i =0; i<s.size(); i++){
        vector<int> hashArray(256,0);
        for(int j=i; j<s.size(); j++){
            if(hashArray[s[j]] == 1) break;
            int len = j - i + 1;
            lenMax = max(lenMax,len);
            hashArray[s[j]] = 1;
        }
    }
    return lenMax;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
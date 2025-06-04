#include<bits/stdc++.h>
using namespace std;

// TC - O(n^2), SC - O(256) size of hash array
int lengthOfLongestSubstring1(string s){
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

// two pointer sliding window approach - TC: O(n) and SC: O(256) for the hash array
int lengthOfLongestSubstring(string s){
    int l=0, r=0;
    vector<int> hashArray(256,-1);
    int n = s.size();
    int lenMax = 0;
    while(r < n){
        if(hashArray[s[r]] != -1){
            if(hashArray[s[r]] >= l){
                l = hashArray[s[r]] + 1;
            }
        }
        int len = r-l +1;
        lenMax = max(len,lenMax);
        hashArray[s[r]] = r;
        r++;
    }

    return lenMax;
}

int main(){
    string s = "cadbzabcd";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
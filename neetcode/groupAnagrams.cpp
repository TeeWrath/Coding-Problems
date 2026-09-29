#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;

        vector<int> sm(26,0);
        vector<int> tm(26,0);
        for(int i=0;i<s.length();i++){
            sm[s[i]-'a']++;
            tm[t[i]-'a']++;
        }

        return sm == tm;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<bool> mark(n,0);

        for(int i=0;i<n;i++){
            if(mark[i] == 0){
            vector<string> tmp;
            tmp.push_back(strs[i]);
            mark[i] = 1;
            for(int j=0;j<n;j++){
                if(mark[j]==0 && j!=i){
                    if(isAnagram(strs[i],strs[j]) == true){
                        tmp.push_back(strs[j]);
                        mark[j] = 1;
                    }
                }
            }
            ans.push_back(tmp);
        }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<vector<int>,vector<string>> mpp;
        for(auto i : strs){
            vector<int> count(26,0);
            for(auto c : i){
                count[c - 'a'] += 1;
            }
            mpp[count].push_back(i);
        }

        vector<vector<string>> res;
        for(auto i : mpp){
            res.push_back(i.second);
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    // cout << Solution().isAnagram(strs[0],strs[3]) << endl;
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    for(auto i : ans){
        cout << "[ ";
        for (auto j : i){
            cout << j << " ";
        }
        cout << "],";
        // cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int maxLen=0;
        set<char> st;
        int l =0;
        for(int r =0;r<n;r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen,r-l+1);
        }

        return maxLen;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int maxLen=0;
        map<char,int> mpp;
        int l =0;
        for(int j=0;j<n;j++){
            if(mpp.count(s[j]) && mpp[s[j]] >=l){
                l = mpp[s[j]] + 1;
            }
            mpp[s[j]] = j;
            maxLen = max(maxLen,j-l+1);
        }

        return maxLen;
    }
};

int main()
{
    // string s = "pwwkew";
    string s = "dvdf";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
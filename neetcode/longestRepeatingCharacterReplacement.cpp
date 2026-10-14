#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        map<char, int> mpp;
        mpp[s[0]] = 0;
        int cnt = k;
        int maxLen = 0;
        int l = 0, r = l + 1;
        while (r < n)
        {
            if (s[r] == s[l])
            {
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
            else if (s[r] != s[l])
            {
                if (cnt > 0)
                {
                    cnt--;
                    mpp[s[r]] = r;
                    maxLen = max(maxLen, r - l + 1);
                    r++;
                }
                else
                {
                    cnt = k;
                    mpp.erase(s[l]);
                    if (!mpp.empty())
                    {
                        l = mpp[s[r]];
                        r = l + 1;
                    }
                    else
                    {
                        l = r;
                        r++;
                    }
                    if(r<n)maxLen = max(maxLen, r - l + 1);
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    string s = "ABCDE";
    int k = 1;
    cout << Solution().characterReplacement(s, k) << endl;
    return 0;
}
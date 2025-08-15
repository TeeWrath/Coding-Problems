#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2 + 1, 0);
        vector<int> cur(n2 + 1, 0);

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            prev = cur;
        }

        return prev[n2];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        string revs = string(s.rbegin(), s.rend());
        return longestCommonSubsequence(s, revs);
    }

public:
    int minInsertions(string s)
    {
        int n = s.size();
        int k = longestPalindromeSubseq(s);
        return n - k;
    }
};
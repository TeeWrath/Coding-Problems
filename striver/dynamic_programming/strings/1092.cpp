#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        int len = dp[n1][n2];
        string str = "";
        int i = n1, j = n2, ind = len - 1;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                str += str1[i - 1];
                ind--;
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                str += str1[i-1];
                i--;
            }
            else
            {
                str += str2[j-1];
                j--;
            }
        }

        while(i>0){
            str += str1[i-1];
            i--;
        }
        while(j>0){
            str += str2[j-1];
            j--;
        }

        reverse(str.begin(),str.end());
        return str;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int diff = start ^ goal;
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if (diff & (1 << i))
                cnt++;
        }

        return cnt;
    }
};
#include <bits/stdc++.h>
using namespace std;

// poor time complexity - O(n^2)
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    const int MOD = 1e9 + 7;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int minNum = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minNum = min(arr[j], minNum);
            res = (res + minNum) % MOD;
        }
    }
    return res;
}
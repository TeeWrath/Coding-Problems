#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[j] >= g[i])
        {
            i++;
        }
        j++;
    }

    return i;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << findContentChildren(g, s) << endl;
    return 0;
}
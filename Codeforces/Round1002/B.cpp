#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == k)
    {
        int l = 1;
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] == l)
            {
                l++;
                continue;
            }
            break;
        }
        return l;
    }
    int ans = 2;
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (a[i] != 1)
        {
            ans = 1;
            return ans;
        }
    }

    return ans;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int res = solve();
        cout << res << endl;
    }
    return 0;
}
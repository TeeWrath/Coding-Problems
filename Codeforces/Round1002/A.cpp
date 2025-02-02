#include <bits/stdc++.h>
using namespace std;

void solve()
{

    // Length of arrays
    int n;
    cin >> n;
    // defining set so that we can track distinct elements
    set<int> a;
    set<int> b;

    // Filling the arrays and sets
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }

    // if the multiplication of the no. of distinct elements in a and b is not equal or greater than 3
    if (a.size() * b.size() >= 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    // Number of test cases
    int test;
    cin >> test;

    while (test--)
    {
        solve();
    }
    return 0;
}
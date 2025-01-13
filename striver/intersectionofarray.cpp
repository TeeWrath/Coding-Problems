#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArray(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    vector<int> interscn;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            if (interscn.size() == 0 || interscn.back() != a[i])
                interscn.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++; // Move forward in array `a` to catch up with `b`
        }
        else
        {
            j++; // Move forward in array `b` to catch up with `a`
        }
    }
    return interscn;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 5, 6, 9};
    vector<int> arr = intersectionOfArray(a, b);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
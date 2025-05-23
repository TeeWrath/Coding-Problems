#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> &arr, int index, int sum, vector<int> &res)
{
    if (index == arr.size())
    {
        res.push_back(sum);
        return;
    }

    subsetSum(arr, index + 1, sum + arr[index], res);

    subsetSum(arr, index + 1, sum, res);
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> res;

    subsetSum(arr, 0, 0, res);
    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << endl;
    cout << "Now the k: ";
    int k;
    cin >> k;

    // int res = longestSubarrayWithSumK(nums, k);
    // cout << "Result is: " << res << endl;

    // for(int i=0;i<n;i++){
    //     cout << nums[i] << " ";
    // }
    return 0;
}
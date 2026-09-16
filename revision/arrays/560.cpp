#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt=0;
    unordered_map<int,int> mpp;
    int prefSum = 0;

    mpp[0] = 1;

    for(int i=0;i<n;i++){
        prefSum += nums[i];
        int rem = prefSum - k;

        if(mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }

        mpp[prefSum]++;
    }
    return cnt;
}

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

    int res = subarraySum(nums, k);
    cout << "Result is: " << res << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    return 0;
}
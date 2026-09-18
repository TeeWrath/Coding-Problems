#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(const vector<int> &nums, int target,
                           int fixedIndex)
{
    vector<vector<int>> pairs;
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i == fixedIndex)
            continue;

        int complement = target - nums[i];

        if (seen.count(complement))
        {
            pairs.push_back({complement, nums[i]});
        }

        seen.insert(nums[i]);
    }

    return pairs;
}

// vector<vector<int>> threeSum(vector<int>& nums) {
//     set<vector<int>> uniqueTriplets;

//     for (int i = 0; i < nums.size(); i++) {
//         auto pairs = twoSum(nums, -nums[i], i);

//         for (auto pair : pairs) {
//             pair.push_back(nums[i]);
//             sort(pair.begin(), pair.end());
//             uniqueTriplets.insert(pair);
//         }
//     }

//     return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
// }

// brute aproach
// vector<vector<int>> threeSum(vector<int>& nums) {
//     int n = nums.size();

//     set<vector<int>> st;

//     for(int i =0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 if(nums[i]+nums[j]+nums[k] == 0){
//                     vector<int> tmp = {nums[i],nums[j],nums[k]};
//                     sort(tmp.begin(),tmp.end());
//                     st.insert(tmp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hash;
        for (int j = i + 1; j < n; j++)
        {
            if (hash.find(-(nums[i] + nums[j])) != hash.end())
            {
                vector<int> tmp = {nums[i], nums[j], -(nums[i] + nums[j])};
                sort(tmp.begin(), tmp.end());
                st.insert(tmp);
            }
            hash.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &num : nums)
    {
        cin >> num;
    }

    auto triplets = threeSum(nums);

    for (const auto &triplet : triplets)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
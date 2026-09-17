#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(const vector<int>& nums, int target,
                           int fixedIndex) {
    vector<vector<int>> pairs;
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++) {
        if (i == fixedIndex) continue;

        int complement = target - nums[i];

        if (seen.count(complement)) {
            pairs.push_back({complement, nums[i]});
        }

        seen.insert(nums[i]);
    }

    return pairs;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < nums.size(); i++) {
        auto pairs = twoSum(nums, -nums[i], i);

        for (auto pair : pairs) {
            pair.push_back(nums[i]);
            sort(pair.begin(), pair.end());
            uniqueTriplets.insert(pair);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    auto triplets = threeSum(nums);

    for (const auto& triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
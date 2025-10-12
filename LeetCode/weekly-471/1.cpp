#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        map<int,int> mpp;

        for(int i=0;i<n;i++){
            if(mpp.find(nums[i]) == mpp.end()) mpp[nums[i]] = 1;
            else mpp[nums[i]]++;
        }

        for(auto it: mpp){
            if(it.second % k == 0)sum += (it.first*it.second);
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,4,4,1,2,3};
    int k=3;
    cout << Solution().sumDivisibleByK(nums,k)<<endl;
    return 0;
}

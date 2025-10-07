#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            if(n==1)return k == nums[0] ? 1 : 0;
            int i=0,j=0;
            int cnt=0;
            int sum=nums[0];
            while(i<n && j<n){
                if(sum==k){
                    cnt++;
                    j++;
                    sum+= nums[j];
                }
                else if(sum > k){
                    sum -= nums[i];
                    i++;
                }else{
                    j++;
                    sum+= nums[j];
                }
            }

            return cnt;
        }
    };

    int main(int argc, char const *argv[])
    {
        vector<int> nums = {1,1,1};
        cout << Solution().subarraySum(nums,2) << endl;
        return 0;
    }
    
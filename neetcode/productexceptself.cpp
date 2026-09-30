#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int x = 1;
        int y = x;

        for(auto i: nums){
            if(x ==0 && i == 0)y=0;
            else if(i==0)x = 0;
            else {
                x *= i;
                y *= i;
            }

        }
        vector<int> res;
        for(auto i:nums){
            // if(i == 0 && y==0)res.push_back(0);
            if(i==0)res.push_back(y);
            else res.push_back(x/i);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,1);
        vector<int> suff(n,1);
        vector<int> res(n);

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]*nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            res[i]= pref[i] * suff[i];
        }

        return res;
    }
};


int main(){
    vector<int> nums = {0,0};

    vector<int> res = Solution().productExceptSelf(nums);
    for(auto i:res){
        cout << i << " ";
    }
    cout << endl;
}
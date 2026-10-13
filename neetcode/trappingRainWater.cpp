#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefSum(n);
        vector<int> suffSum(n);

        int maxNum = INT_MIN;
        for(int i=0;i<n;i++){
            if(height[i] > maxNum)maxNum = height[i];
            prefSum[i] = maxNum;
        }
        maxNum = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(height[i] > maxNum)maxNum = height[i];
            suffSum[i] = maxNum;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(prefSum[i],suffSum[i]) - height[i];
        }

        return ans;
    }
};


int main(){
    vector<int> nums = {0,2,0,3,1,0,1,3,2,1};
    cout << Solution().trap(nums) <<endl;
    return 0;
}
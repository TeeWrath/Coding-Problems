#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxValue(vector<int>& nums) {
            int n=nums.size();
            vector<int> left(n);
            vector<int> right(n);
            vector<int> ans(n);
            left[0]=nums[0];
            for(int i=1;i<n;i++){
                left[i]=max(left[i-1],nums[i]);
            }
            right[n-1]=nums[n-1];
            for(int i=n-2;i>=0;i--){
                right[i]=min(right[i+1],nums[i]);
            }
            int start=0;
            int maxi=nums[0];
            for(int i=0;i<n-1;i++){
                maxi=max(maxi,nums[i]);
                if(left[i]<=right[i+1]){
                    for(int j=start;j<=i;j++){
                        ans[j]=maxi;
                    }
                    start=i+1;
                    if(start<n){
                        maxi=nums[start];
                    }
                }
            }
            maxi=max(maxi,nums[n-1]);
            for(int j=start;j<n;j++){
                ans[j]=maxi;
            }
            return ans;
        }
    };
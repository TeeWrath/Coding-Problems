#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
    
            for(int num =0; num < (1 << n); num++){
                vector<int> s;
                for(int i=0; i< n; i++){
                    if((num & (1 << i)) != 0){
                        s.push_back(nums[i]);
                    }
                }
                ans.push_back(s);
            }
            return ans;
        }
    };

// Using recursion
class Solution {
    public:
        void fun(int idx,vector<int> & nums, vector<int> &l, vector<vector<int>> & ans){
            int n = nums.size();
            if(idx>=n){
                ans.push_back(l);
                return;
            }
            l.push_back(nums[idx]);
            fun(idx+1,nums,l,ans);
            l.erase(l.begin()+idx);
            fun(idx+1,nums,l,ans);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
            vector<int> l;
            fun(0,nums,l,ans);
            return ans;
        }
    };
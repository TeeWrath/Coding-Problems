#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int m = queries.size();
            const int MOD = 1e9+7;
    
            int idx=0;
            int i=0;
            while(i<m){
                idx = queries[i][0]; //li
                while(idx <= queries[i][1]){
                    nums[idx] = (static_cast<long long>(nums[idx])*queries[i][3]) % MOD;
                    idx += queries[i][2];
                }
                i++;
            }
    
            int xorr = 0;
            for(int i=0;i<n;i++){
                xorr = xorr ^ nums[i];
            }
    
            return xorr;
        }
    };
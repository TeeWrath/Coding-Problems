#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> ds;
            findComb(candidates, target, 0, ds, ans);
            return ans;
        }
    
        void findComb(vector<int>& candidates, int target, int index, vector<int> &ds, vector<vector<int>>& ans){
            if(target == 0){
                ans.push_back(ds);
                return;
            }
            for(int i = index ; i < candidates.size() ; i++){
                if(i > index && candidates[i] == candidates[i-1])continue;
                if(candidates[i] > target) break;
                ds.push_back(candidates[i]);
                findComb(candidates,target - candidates[i], i + 1,ds, ans);
                ds.pop_back();
            }
        }
    };
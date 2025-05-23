#include <bits/stdc++.h>
using namespace std;

// most optimal
class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> comb;
            findCom(candidates,0,target,comb,ans);
            return ans;
    
        }
    
        void findCom(vector<int> & candidates, int index, int target, vector<int> &comb, vector<vector<int>> &ans){
            if(index == candidates.size()){
                if(target == 0){
                    ans.push_back(comb);
                }
                return;
            }
    
            if(candidates[index] <= target){
                comb.push_back(candidates[index]);
                findCom(candidates, index, target - candidates[index], comb, ans);
                comb.pop_back();
            }
    
            findCom(candidates,index+1,target,comb,ans);
        }
    };
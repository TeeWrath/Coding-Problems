#include<bits/stdc++.h>
#include "disjoint_set.h"
using namespace std;

class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            DisjointSet ds(accounts.size());
            map<string,int> mailToNode;
            for(int i=0; i<accounts.size();i++){
                for(int j=1; j<accounts[i].size();j++){
                    string mail = accounts[i][j];
                    if(mailToNode.find(mail) == mailToNode.end())mailToNode[mail]=i;
                    else{
                        ds.unionBySize(i,mailToNode[mail]);
                    }
                }
            }

            vector<vector<string>> merged(accounts.size());
            for(auto it:mailToNode){
                string mail = it.first;
                int parent = ds.findUltimateParent(it.second);
                merged[parent].push_back(mail);
            }

            vector<vector<string>> res;
            for(int i=0;i<accounts.size();i++){
                if(merged[i].empty())continue;
                sort(merged[i].begin(),merged[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto& mail:merged[i]){
                    temp.push_back(mail);
                }

                res.push_back(temp);
            }

            return res;
        }
    };
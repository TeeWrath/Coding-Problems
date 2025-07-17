#include <bits/stdc++.h>
#include "disjoint_set.h"
using namespace std;

class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            int maxRow=0,maxCol=0;
            for(auto it: stones){
                maxRow = max(maxRow,it[0]);
                maxCol = max(maxCol,it[1]);
            }
            DisjointSet ds(maxRow + maxCol + 1);

            for(auto it:stones){
                int row = it[0];
                int col = it[1]+maxRow+1;
                ds.unionBySize(row,col);
            }
            int cnt=0;
            for(int i=0;i<ds.parent.size();i++){
                if(ds.findUltimateParent(i) == i && ds.size[i] > 1)cnt++;
            }

            return stones.size()- cnt;
        }
    };
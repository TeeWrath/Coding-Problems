#include <bits/stdc++.h>
#include "disjoint_set.h"
using namespace std;

class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            DisjointSet ds(n);
            int cntEdges = 0;
            for(auto it:connections){
                int u = it[0];
                int v = it[1];
                if(ds.findUltimateParent(u) == ds.findUltimateParent(v))cntEdges++;
                else ds.unionBySize(u,v);
            }

            int cntC=0;
            for(int i=0; i<n; i++){
                if(ds.parent[i] == i)cntC++;
            }
            int ans = cntC-1;
            if(cntEdges >= ans)return ans;
            return -1;
        }
    };
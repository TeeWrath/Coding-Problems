#include <bits/stdc++.h>
#include "disjoint_set.h"
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){
    // create edge list first
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<V; i++){
        for(auto it: adj[i]){
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjnode}});
        }
    }

    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstWt=0;

    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            mstWt += wt;
            ds.unionBySize(u,v);
        }
    }
    return mstWt;
}
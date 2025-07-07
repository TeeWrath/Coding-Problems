#include<bits/stdc++.h>
using namespace std;

bool bfsDetecCycle(int n,vector<vector<int>>& adj){
    vector<int> vis(n+1,0);
    queue<pair<int,int>> q;
    q.push({1,-1});
    vis[1] = 1;

    while(!q.empty()){
        int source = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: adj[source]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,source});
            }
            else if(it != parent) return true;
        }
    }

    return false;
}

bool dfsDetecCycle(vector<vector<int>>& adj,vector<int> &vis, int parent, int curNode){
    vis[curNode] = 1;

    for(auto it: adj[curNode]){
        if(!vis[it]){
            if(dfsDetecCycle(adj,vis,curNode,it)) return true;
        }
        else if(it != parent) return true;
    }

    return false;
}
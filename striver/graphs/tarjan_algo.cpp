#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int timer =1;
    private:
        void dfs(int node, int parent, vector<int>&vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridge){
            vis[node]=1;
            tin[node]=low[node]=timer;
            timer++;
            for(auto it: adj[node]){
                if(it == parent)continue;
                if(!vis[it]){
                    dfs(it,node,vis,adj,tin,low,bridge);
                    low[node]= min(low[node], low[it]);

                    // node --it can it be a bridge?
                    if(low[it] > tin[node]){ // adj node needs more steps to reach than current node, so if edge removed, componenets will break
                        bridge.push_back({node,it});
                    }
                }
                else low[node] = min(low[node],low[it]); // this wont be a bridge for sure because you have already visited, but node will take its lowest time
            }
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
            for(auto it:connections){
                // undirected graph
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }

            vector<int> vis(n,0), tin(n),low(n);
            vector<vector<int>> bridges;
            dfs(0,-1,vis,adj,tin,low,bridges);
            return bridges;
        }
    };
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it,vis,adj,st);
        }

        st.push(node);
    }
private:
    void dfs2(int node,vector<int>& vis,vector<vector<int>>& adjT, vector<int>& tmp){
        tmp.push_back(node);
        vis[node]=1;

        for(auto it:adjT[node]){
            if(!vis[it]){
                dfs2(it,vis,adjT,tmp);
            }
        }
    }
public:
    int kosaraju(vector<vector<int>> &adj)
    {
        int n = adj.size();

        // storing nodes in order of finishing time
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,vis,adj,st);
        }

        // reverse the edges
        vector<vector<int>> adjT(n);
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }

        // perform dfs
        vector<vector<int>> scc;
        while(!st.empty()){
            int node = st.top(); st.pop();
            vector<int> tmp;
            if(!vis[node]){
                dfs2(node,vis,adjT,tmp);
            }
            if(tmp.size() > 0) scc.push_back(tmp);
        }

        return scc.size();
    }
};
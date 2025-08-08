#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createUndirectedGraph(int n, int m){
    vector<vector<int>> adjacent(n+1);
    cout << "Creating Undirected Graph" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter node values for edges (u and v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    return adjacent;
}

void printGraph(vector<vector<int>> graph){
    for(auto it: graph){
        for(int i=0; i< it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
}

bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>>& adj){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,adj)) return true;
        }
        else{
            if(it != parent) return true;
        }
    }

    return false;
}

bool isCycle(int n,vector<vector<int>>& adj){
    vector<int> vis(n+1,0);

    for(int i=0;i<=n;i++){
        if(!vis[i]) if(dfs(i,-1,vis,adj)) return true;
    }
    return false;
}

int main(){
    int n,m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> udg = createUndirectedGraph(n,m);
    cout << "undirected" << endl;
    printGraph(udg);
    cout << "is cycle present in the graph ?: "<< isCycle(n,udg)<<endl;
    return 0;
}
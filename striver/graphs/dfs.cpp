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
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int node,vector<vector<int>> &graph, vector<int>& vis, vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: graph[node]){
        if(!vis[it]) dfs(it,graph,vis,ls);
    }
}

vector<int> dfsTraversal(int n,vector<vector<int>> &graph){
    vector<int> vis(n+1,0);
    vis[1] = 1;
    int startNode = 1;
    vector<int> ans;

    dfs(startNode,graph,vis,ans);
    return ans;
}

int main(){
    int n,m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> udg = createUndirectedGraph(n,m);
    cout << "Undirected Graph:" << endl;
    printGraph(udg);

    vector<int> bfs = dfsTraversal(n,udg);
    cout << "DFS traversal: "<< endl;
    for(auto it: bfs){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
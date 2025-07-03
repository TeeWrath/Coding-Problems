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

vector<int> bfsTraversal(int n, vector<vector<int>> adj){
    vector<int> vis(n+1,0);
    vector<int> bfs;
    
    // Start from node 1 (assuming 1-based)
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> udg = createUndirectedGraph(n,m);
    cout << "Undirected Graph:" << endl;
    printGraph(udg);

    vector<int> bfs = bfsTraversal(n,udg);
    cout << "BFS traversal: "<< endl;
    for(auto it: bfs){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
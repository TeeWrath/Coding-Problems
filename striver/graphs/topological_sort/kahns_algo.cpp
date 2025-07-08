#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createDirectedGraph(int n, int m)
{
    vector<vector<int>> adjacent(n); // 0-based indexing
    cout << "Creating Directed Graph" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter node values for edges (from u to v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    return adjacent;
}

void printGraph(vector<vector<int>> graph)
{
    // Print only nodes 0 to n-1
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Node " << i << ": ";
        for (int j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<int> kahnsAlgorithm(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> indegree(n,0);
    // creating indegree vector
    for(int i=0; i<n; i++){
        for(auto it: adj[i]) indegree[it]++;
    }

    queue<int> q;

    for(int i=0; i<n; i++){
        if(indegree[i] == 0)q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
    }

    return topo;
}

int main()
{
    int n, m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> dg = createDirectedGraph(n, m);
    cout << "Directed Graph:" << endl;
    printGraph(dg);
    
    vector<int> topo = kahnsAlgorithm(dg);
    cout << "After topo sort: "<< endl;
    for(auto it: topo){
        cout << it << " ";
    }
    return 0;
}
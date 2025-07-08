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
class TopologicalSort
{
private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]) dfs(adjacentNode,vis,st,adj);
        }
        st.push(node);
    }

public:
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }

        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top()); st.pop();
        }

        return topo;
    }
};

int main()
{
    int n, m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> dg = createDirectedGraph(n, m);
    cout << "Directed Graph:" << endl;
    printGraph(dg);

    TopologicalSort topologicalSort = TopologicalSort();
    vector<int> topo = topologicalSort.topologicalSort(dg);
    cout << "After topo sort: "<< endl;
    for(auto it: topo){
        cout << it << " ";
    }
    return 0;
}
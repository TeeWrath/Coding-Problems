#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createDirectedGraph(int n, int m) {
    vector<vector<int>> adjacent(n + 1); // 1-based indexing
    cout << "Creating Directed Graph" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter node values for edges (from u to v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    return adjacent;
}

void printGraph(vector<vector<int>> graph) {
    // Print only nodes 1 to n (skip index 0)
    for (int i = 1; i < graph.size(); i++) {
        cout << "Node " << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj)) return true;
            } else if (pathVis[it]) {
                return true; // Cycle detected
            }
        }
        pathVis[node] = 0; // Backtrack: remove node from current path
        return false;
    }

public:
    bool isCyclic(int n, vector<vector<int>>& adj) {
        vector<int> vis(n + 1, 0); // 1-based indexing
        vector<int> pathVis(n + 1, 0);

        // Start DFS from nodes 1 to n
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return true;
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> dg = createDirectedGraph(n, m);
    cout << "Directed Graph:" << endl;
    printGraph(dg);
    Solution sol;
    cout << "The graph is cyclic or not: " << (sol.isCyclic(n, dg) ? "Yes" : "No") << endl;
    return 0;
}
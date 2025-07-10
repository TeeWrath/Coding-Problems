#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topo(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                topo(it.first, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int n, int m, int src, vector<vector<int>> &edges)
    {
        // create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // topo sort
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                topo(i, adj, vis, st);
        }

        // calculate distance
        vector<int> distance(n, 1e9);
        distance[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                if (distance[node] + it.second < distance[it.first])
                    distance[it.first] = distance[node] + it.second;
            }
        }

        return distance;
    }
};
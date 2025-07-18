#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0; // for first node logic

        // Main logic
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, adj, tin, low, mark);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
                low[node] = min(low[node], tin[it]);
        }
        if (child > 1 && parent == -1)
            mark[node] = 1;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, vis, adj, tin, low, mark);
        }

        vector<int> articulationPoints;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
                articulationPoints.push_back(i);
        }
        if (articulationPoints.size() == 0)
            return {-1};
        return articulationPoints;
    }
};
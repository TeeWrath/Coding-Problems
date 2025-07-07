#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int col, int node)
    {
        color[node] = col;

        for (int neighbor : graph[node])
        {
            if (color[neighbor] == -1)
            {
                if (!dfs(graph, color, 1 - col, neighbor))
                    return false;
            }
            else if (col == color[neighbor])
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);

        for (int node = 0; node < graph.size(); node++)
        {
            if (color[node] == -1)
            {
                if (!dfs(graph, color, 0, node))
                    return false;
            }
        }

        return true;
    }
};
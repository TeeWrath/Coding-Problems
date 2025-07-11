#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        set<pair<int,int>> st;
        vector<int> distance(V,1e9);
        distance[src] = 0;
        st.insert({0,src});

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dist = it.first;
            st.erase(it);

            for(auto it: adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(edgeWeight + dist < distance[adjNode]){
                    if(distance[adjNode] != 1e9)st.erase({distance[adjNode],adjNode});
                    distance[adjNode] = edgeWeight + dist;
                    st.insert({distance[adjNode],adjNode});
                }
            }
        }

        return distance;
    }
};
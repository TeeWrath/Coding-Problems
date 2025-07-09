#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size(); // nodes
        vector<int> distance(n,INT_MAX);
        queue<int> q;
        q.push(src);
        distance[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjacentNode: adj[node]){
                if(distance[node] + 1 < distance[adjacentNode]){
                    distance[adjacentNode] = 1 + distance[node];
                    q.push(adjacentNode);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(distance[i] == INT_MAX) distance[i] = -1;
        }

        return distance;
      }
  };
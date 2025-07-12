#include <bits/stdc++.h>
using namespace std;

class SolutionSet {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto it : roads) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
    
            vector<long long> distance(n, 1e18); // Use long long for distances
            vector<int> ways(n, 0);
            distance[0] = 0;
            ways[0] = 1;
            set<pair<long long, int>> st; // Correct type: long long for distance, int for node
            st.insert({0, 0});
    
            int mod = 1e9 + 7;
    
            while (!st.empty()) {
                auto it = *st.begin();
                st.erase(it);
                long long dist = it.first; // Use long long for distance
                int node = it.second;
    
                for (auto [nbrNode, nbrDist] : adj[node]) {
                    long long newDis = dist + nbrDist;
                    if (newDis < distance[nbrNode]) {
                        auto old = st.find({distance[nbrNode], nbrNode});
                        if (old != st.end()) {
                            st.erase(old);
                        }
                        distance[nbrNode] = newDis;
                        ways[nbrNode] = ways[node];
                        st.insert({newDis, nbrNode});
                    }
                    else if (newDis == distance[nbrNode]) {
                        ways[nbrNode] = (ways[nbrNode] + ways[node]) % mod;
                    }
                }
            }
    
            return ways[n-1] % mod;
        }
    };

// faster using priority queue
class SolutionPq {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto it : roads) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
    
            vector<long long> distance(n, 1e18); // Use long long for distances
            vector<int> ways(n, 0);
            distance[0] = 0;
            ways[0] = 1;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, 0});
    
            int mod = 1e9 + 7;
    
            while (!pq.empty()) {
                auto [dist, node] = pq.top();
                pq.pop();
    
                // Skip outdated entries
                if (dist > distance[node]) continue;
    
                for (auto [nbrNode, nbrDist] : adj[node]) {
                    long long newDis = dist + nbrDist;
                    if (newDis < distance[nbrNode]) {
                        distance[nbrNode] = newDis;
                        ways[nbrNode] = ways[node];
                        pq.push({newDis, nbrNode});
                    }
                    else if (newDis == distance[nbrNode]) {
                        ways[nbrNode] = (ways[nbrNode] + ways[node]) % mod;
                    }
                }
            }
    
            return ways[n-1] % mod;
        }
    };
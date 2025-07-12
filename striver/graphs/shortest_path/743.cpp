#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>> adj(n+1);
            for(auto edges: times){
                int u = edges[0];
                int v = edges[1];
                int t = edges[2];
                adj[u].push_back({v,t});
            }

            vector<int> distance(n+1,1e9);
            distance[k] = 0;
            set<pair<int,int>> st; // Min-heap
            st.insert({0,k});

            while(!st.empty()){
                auto it = *(st.begin());
                st.erase(it);
                int node = it.second;
                int dist = it.first;

                for(auto adjnode:adj[node]){
                    int newDist = dist + adjnode.second;
                    if(newDist < distance[adjnode.first]){
                        distance[adjnode.first] = newDist;
                        auto result = st.find({distance[adjnode.first],adjnode.first});
                        if(result != st.end())st.erase(result);
                        st.insert({newDist,adjnode.first});
                    }
                }
            }

            int maxDis = 0;
            for(int it = 1; it<distance.size(); it++){
                if(distance[it] == 1e9)return -1;
                maxDis = max(maxDis,distance[it]);
            }

            return maxDis;
        }
    };
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                dist[u][v] = wt;
                dist[v][u] = wt;
            }

            for(int i=0; i<n; i++)dist[i][i]=0;

            for(int via = 0; via<n;via++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)continue;
                        dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                    }
                }
            }

            int cntCity = n;
            int cityNo=-1;

            for(int city=0; city<n;city++){
                int cnt=0;
                for(int adjcity=0;adjcity<n;adjcity++){
                    if(dist[city][adjcity] <= distanceThreshold)cnt++;
                }

                if(cnt <= cntCity){
                    cntCity = cnt;
                    cityNo=city;
                }
            }

            return cityNo;
        }
    };
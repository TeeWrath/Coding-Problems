#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void floydWarshall(vector<vector<int>>& dist) {
            int n = dist.size();
            // Use long long for intermediate calculations to avoid overflow
            for (int via = 0; via < n; via++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        // Only compute if both distances are not infinity
                        if (dist[i][via] != 1e8 && dist[via][j] != 1e8) {
                            dist[i][j] = min((long long)dist[i][j], (long long)dist[i][via] + dist[via][j]);
                        }
                    }
                }
            }
        }
    };
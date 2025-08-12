#include<bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    public:
        long long maxTotal(vector<int>& value, vector<int>& limit) {
            int n = value.size();
            unordered_map<int,vector<int>> u;
            for(int i=0;i<n;i++){
                u[limit[i]].push_back(value[i]);
            }

            ll ans =0;
            for(int lim = 1; lim <=n;lim++){
                if(!u.count(lim))continue;
                sort(u[lim].rbegin(),u[lim].rend());
                for(int i=0;i < min(lim,(int)u[lim].size());i++){
                    ans += u[lim][i];
                }
            }

            return ans;
        }
    };
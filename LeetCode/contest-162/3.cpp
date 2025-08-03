#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
            int n = ls.size();
            int m = ws.size();
            
            int enda = 1e9, endb = 1e9;
            for(int i = 0; i < n; i++) {
                enda = min(ls[i]+ld[i], enda);
            }
            for(int i = 0; i < m; i++) {
                endb = min(ws[i]+wd[i], endb);
            }
    
            int pa = 1e9, pb = 1e9;
            for(int i = 0; i < m; i++) {
                pa = min(pa, max(enda+wd[i], ws[i]+wd[i]));
            }
            for(int i = 0; i < n; i++) {
                pb = min(pb, max(endb+ld[i], ls[i]+ld[i]));
            }
    
            return min(pa, pb);
        }
    };
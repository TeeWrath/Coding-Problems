#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
            int m = grid.size();
            int n = grid[0].size();
    
            if(x<0 || y<0 || x+k>m || y+k>n)return grid;
    
            vector<vector<int>> mat = grid;
            for(int i=0;i<k;i++){
                for(int j=0;j<k;j++){
                    mat[x+k-1-i][y+j]=grid[x+i][y+j];
                }
            }
    
            for(int i=x;i<x+k;i++){
                for(int j=y;j<y+k;j++){
                    grid[i][j] = mat[i][j];
                }
            }
    
            return grid;
        }
    };
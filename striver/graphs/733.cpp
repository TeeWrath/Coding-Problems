#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            if(image[sr][sc] == color) return image;
            int n = image.size();
            int m = image[0].size();
            int startColor = image[sr][sc];
            queue<pair<int,int>> q;
            image[sr][sc] = color;
            q.push({sr,sc});

            int dRow[] = {1,-1,0,0};
            int dCol[] = {0,0,1,-1};

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int nRow = row + dRow[i];
                    int nCol = col + dCol[i];

                    if(nRow >=0 && nCol >=0 && nRow < n && nCol < m && image[nRow][nCol] == startColor){
                        q.push({nRow,nCol});
                        image[nRow][nCol] = color;
                    }
                }
            }

            return image;
        }
    };
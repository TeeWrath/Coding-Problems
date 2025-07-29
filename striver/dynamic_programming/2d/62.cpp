#include <bits/stdc++.h>
using namespace std;

// memoization
class Solutionm
{
    public:
        int countPaths(int row, int col, int m, int n, vector<vector<int>>& dp){
            if(row==m-1 && col==n-1)return 1;
            if(row >= m || col >=n)return 0;
            if(dp[row][col] != -1)return dp[row][col];
            int right = countPaths(row, col+1,m,n,dp);
            int down = countPaths(row+1,col,m,n,dp);
            return dp[row][col] = right + down;
        }
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countPaths(0,0,m,n,dp);
    }
};

// tabulation
class Solutiont
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }

                int up = 0,left=0;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};

// space optimization
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prevRow(n,0);

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }

                int up=0,left=0;

                if(i>0)up = prevRow[j];
                if(j>0)left = temp[j-1];

                temp[j] = up+left;
            }
            prevRow = temp;
        }

        return prevRow[n-1];
    }
};

// fastest, but space heavy
class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            dp[0][0] = 1;
    
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++) {
                    if(i-1 >= 0) dp[i][j]+= dp[i-1][j]; 
                    if(j-1 >= 0) dp[i][j]+= dp[i][j-1]; 
                }
            }
            return dp[m-1][n-1];
        }
    };

int main()
{
    int m,n; cin >> m >> n;
    cout << "No. of possible paths: "<< Solution().uniquePaths(m,n) << endl;
    return 0;
}
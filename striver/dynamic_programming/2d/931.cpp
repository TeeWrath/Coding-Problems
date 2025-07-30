#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int m = matrix.size();
        vector<int> dp(m, 0);

        for (int i = 0; i < m; i++)
        {
            dp[i] = matrix[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            vector<int> temp(m,0);
            for (int j = m-1; j >= 0; j--)
            {
                    int down = dp[j];
                    int right = INT_MAX,left = INT_MAX;
                    if(j+1 < m) right = dp[j + 1];
                    if(j-1 >=0) left = dp[j-1];

                temp[j] = matrix[i][j] + min(down, min(right,left));
            }
            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
        }
    };

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << "SUM: "<< Solution().minFallingPathSum(matrix) << endl;
    return 0;
}
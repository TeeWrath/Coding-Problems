#include<bits/stdc++.h>
using namespace std;

int fr(int i, int w, vector<int>& price){
    if(i == 0) return w*price[i];
    if(w == 0)return 0;
    
    int notPick = fr(i-1,w,price);
    int pick = INT_MIN;
    if(i+1 <= w)pick = price[i] + fr(i,w-(i+1),price);

    return max(pick,notPick);
}
int cutRodr(vector<int> &price, int n)
{
	return fr(n-1,n,price);
}

// memo
int fm(int i, int w, vector<int>& price, vector<vector<int>> &dp){
    if(i == 0) return w*price[i];
    if(w == 0)return 0;
    if(dp[i][w] != -1)return dp[i][w];
    
    int notPick = fm(i-1,w,price,dp);
    int pick = INT_MIN;
    if(i+1 <= w)pick = price[i] + fm(i,w-(i+1),price,dp);

    return dp[i][w] = max(pick,notPick);
}
int cutRodm(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return fm(n-1,n,price,dp);
}

// tabulation
int cutRodt(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,0));

    for(int i=0;i<=n;i++)dp[0][i] = i*price[0];

    for(int i=1;i<n;i++){
        for(int target = 0;target <=n;target++){
            int notPick = dp[i-1][target];

            int pick = INT_MIN;
            if(i+1<=target)pick = price[i] + dp[i][target - (i+1)];

            dp[i][target] = max(pick,notPick);
        }
    }

    return dp[n-1][n];
}

// space optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0);

    for(int i=0;i<=n;i++)prev[i] = i*price[0];

    for(int i=1;i<n;i++){
        vector<int> cur(n+1,0);
        for(int target = 0;target <=n;target++){
            int notPick = prev[target];

            int pick = INT_MIN;
            if(i+1<=target)pick = price[i] + cur[target - (i+1)];

            cur[target] = max(pick,notPick);
        }
        prev = cur;
    }

    return prev[n];
}

int main(){
    int n = 5;
    vector<int> price = {2,5,7,8,10};
    cout << cutRod(price,n) << endl;
    return 0;
}
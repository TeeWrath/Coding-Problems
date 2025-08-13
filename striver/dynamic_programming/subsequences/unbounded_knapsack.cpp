#include<bits/stdc++.h>
using namespace std;

// recursion
int fr(int i, int w, int n, vector<int>& profit, vector<int>& wt){
    if(i == 0) return (w/wt[0]*profit[0]);
    
    int notPick = fr(i-1,w,n,profit,wt);
    int pick = INT_MIN;
    if(wt[i] <= w)pick = profit[i] + fr(i,w-wt[i],n,profit,wt);

    return max(pick,notPick);
}

int unboundedKnapsackr(int n, int w, vector<int> &profit, vector<int> &weight){
    return fr(n-1,w,n,profit,weight);
}

// memoization
int f(int i, int w, int n, vector<int>& profit, vector<int>& wt,vector<vector<int>> &dp){
    if(i == 0) return (w/wt[0]*profit[0]);
    if(dp[i][w] != -1)return dp[i][w];
    
    int notPick = f(i-1,w,n,profit,wt,dp);
    int pick = INT_MIN;
    if(wt[i] <= w)pick = profit[i] + f(i,w-wt[i],n,profit,wt,dp);

    return dp[i][w] = max(pick,notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,n,profit,weight,dp);
}

int main(){
    int n = 3;
    int w = 10;
    vector<int> profit(n),weight(n);
    profit = {5,11,13};
    weight = {2,4,6};
    cout << unboundedKnapsack(n,w,profit,weight) << endl;
    return 0;
}
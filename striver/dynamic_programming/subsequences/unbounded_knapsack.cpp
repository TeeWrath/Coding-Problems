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
int fm(int i, int w, int n, vector<int>& profit, vector<int>& wt,vector<vector<int>> &dp){
    if(i == 0) return (w/wt[0]*profit[0]);
    if(dp[i][w] != -1)return dp[i][w];
    
    int notPick = fm(i-1,w,n,profit,wt,dp);
    int pick = INT_MIN;
    if(wt[i] <= w)pick = profit[i] + fm(i,w-wt[i],n,profit,wt,dp);

    return dp[i][w] = max(pick,notPick);
}

int unboundedKnapsackm(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return fm(n-1,w,n,profit,weight,dp);
}

// tabulation
int unboundedKnapsackt(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,0));

    for(int i=weight[0];i<=w;i++){
        dp[0][i] = (i/weight[0])*profit[0];
    }

    for(int i=1;i<n;i++){
        for(int target = 0; target <= w;target++){
            int notpick = 0 + dp[i-1][target];
            int pick = INT_MIN;
            if(weight[i] <= target)pick = profit[i] + dp[i][target-weight[i]];

            dp[i][target] = max(pick,notpick);
        }
    }

    if(dp[n-1][w] >= 1e9)return -1;
    return dp[n-1][w];
}

// space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0);

    for(int i=weight[0];i<=w;i++){
        prev[i] = (i/weight[0])*profit[0];
    }

    for(int i=1;i<n;i++){
        vector<int> cur(w+1,0);
        for(int target = 0; target <= w;target++){
            int notpick = 0 + prev[target];
            int pick = INT_MIN;
            if(weight[i] <= target)pick = profit[i] + cur[target-weight[i]];

            cur[target] = max(pick,notpick);
        }
        prev = cur;
    }
    return prev[w];
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
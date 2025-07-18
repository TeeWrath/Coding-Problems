#include<bits/stdc++.h>
using namespace std;

// Memoization, tc - O(N) = sc
int fibbonacci(int n, vector<int>& dp){
    if(n<=1)return n;
    if(dp[n] != -1)return dp[n];
    return dp[n] = fibbonacci(n-1,dp) + fibbonacci(n-2,dp);
}

// Tabulation, tc=sc=O(N)
int fTab(int n,vector<int>& dp){
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// space optimization, tc - O(N), sc - O(1)
int f(int n){
    int prev=1,prev2=0;
    for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    vector<int> dp(11,-1);
    cout << fibbonacci(10,dp) << endl;
    cout << fTab(10,dp)<<endl;
    cout << f(10);
    return 0;
}
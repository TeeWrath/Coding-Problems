#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp(n,1),dp2(n,1);

    // lis
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i],1+dp[prev]);
            }
        }
    }

    //lds
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev] < arr[i]){
                dp2[i] = max(dp2[i],1+dp2[prev]);
            }
        }
    }

    int maxi=-1;

    for(int i=0;i<n;i++){
        maxi = max(maxi,dp[i]+dp2[i]-1);
    }

    return maxi;
}


int main(){
    return 0;
}
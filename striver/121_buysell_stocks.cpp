#include<bits/stdc++.h>
using namespace std;

// Brute
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int profit = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                profit = prices[j] - prices[i];
                maxProfit =  max(profit,maxProfit);
                profit = 0;
            }
        }

        return maxProfit;
    }
};


// Optimal Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(prices[i] - minPrice, maxProfit);
        }

        return maxProfit;
    }
};
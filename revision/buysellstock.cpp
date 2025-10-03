#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
     int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int buy=prices[0];
       int profit =0;

       for(int i=1;i<n;i++){
        profit = max(profit, prices[i] - buy);
        buy = min(buy,prices[i]);
       }

       return profit;
     }
   };

   int main(int argc, char const *argv[])
   {
    vector<int> prices = {7,6,4,3,1};
    cout << Solution().maxProfit(prices)<< endl;
    return 0;
   }
   
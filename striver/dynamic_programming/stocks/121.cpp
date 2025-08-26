#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxprofit =0;
            int mini = prices[0];

            for(int i=0;i<prices.size();i++){
                int curProfit = prices[i] - mini;
                maxprofit = max(maxprofit,curProfit);
                mini = min(mini,prices[i]);
            }

            return maxprofit;
        }
    };

int main(){
    return 0;
}
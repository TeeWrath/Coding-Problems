#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prof = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,prices[i]);
            prof = max(prof,(prices[i]-minPrice));
        }

        return prof;
    }
};

int main(){
    vector<int> nums = {10,8,7,5,2};
    cout << Solution().maxProfit(nums) <<endl;
    return 0;
}
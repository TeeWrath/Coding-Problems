#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0,j=n-1;
        int ans = INT_MIN;
        while(i<j){
            int area = (j-i) * min(heights[i],heights[j]);
            ans = max(ans,area);
            if(heights[i] <= heights[j])i++;
            else j--;
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,2};
    cout << Solution().maxArea(nums) <<endl;
    return 0;
}
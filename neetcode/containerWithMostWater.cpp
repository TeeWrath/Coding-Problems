#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        pair<int,int> minW = {INT_MAX,0};
        pair<int,int> maxW = {INT_MIN,0};

        int maxArea = INT_MIN;

        for(int i=0;i<n;i++){
            if(heights[i]<minW.first)minW = {heights[i],i};
            if(heights[i] > maxW.first)maxW = {heights[i],i};
            int minInd = min(minW.second,maxW.second);
            cout << minInd<< endl;
            int maxInd = max(minW.second,maxW.second);
            cout << maxInd<< endl;
            int width = maxInd - minInd;
            cout << width<< endl;
            int height = min(minW.first,maxW.first);
            cout << height<< endl;
            maxArea = max(maxArea,width*height);
            cout << maxArea<< endl;
        }

        return maxArea;
    }
};

int main(){
    vector<int> nums = {1,7,2,5,4,7,3,6};
    cout << Solution().maxArea(nums)<<endl;
    return 0;
}
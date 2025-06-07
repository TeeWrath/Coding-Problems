#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps =0,l=0,r=0;
    while(r<n-1){
        int farthest = 0;
        for(int i=l; i<=r; i++){
            farthest = max(farthest,i+nums[i]);
        }
        l =r+1;
        r = farthest;
        jumps++;
    }

    return jumps;
}

int main(){
    vector<int> nums = {2,3,0,1,4};
    cout << jump(nums) <<  endl;
    return 0;
}
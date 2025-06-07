#include<bits/stdc++.h>
using namespace std;

// O(n)
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int i=0;
    int maxInd = 0;
    while(i<n){
        if(i>maxInd) return false;
        maxInd = max(maxInd,i+nums[i]);
        i++;
    }
    return true;
}

int main(){
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) <<  endl;
    return 0;
}
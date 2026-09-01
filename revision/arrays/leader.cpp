#include <bits/stdc++.h>
using namespace std;

void leaderInArray(vector<int>& nums){
    int n = nums.size();
    int lastLeader = nums[n-1];
    cout << lastLeader << " ";

    for(int i=n-2;i>=0;i--){
        if(nums[i] > lastLeader){
            lastLeader = nums[i];
            cout << lastLeader << " ";
        }
    }
}

int main(){
    // vector<int> nums = {10,22,12,3,0,6};
    vector<int> nums = {4,7,1,0};
    leaderInArray(nums);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums){
    long xorr = 0; // do not make this int
    for(int i =0; i< nums.size(); i++) xorr = xorr ^ nums[i];

    int rightMost = (xorr & (xorr - 1)) & xorr;
    int b1 =0;
    int b2 =0;

    for(int i=0 ; i< nums.size() ; i++){
        if(nums[i] & rightMost){
            b1 = b1 ^ nums[i];
        }
        else{
            b2 = b2 ^ nums[i];
        }
    }

    return {b1,b2};
}

int main(){
    vector<int> nums = {1,2,3,1,5,2};
    vector<int> ans = singleNumber(nums);

    for(int i =0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
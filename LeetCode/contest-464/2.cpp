#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool partitionArray(vector<int>& nums, int k) {
            int n = nums.size();
            if(n%k !=0)return false;

            map<int,int> hash;
            for(int i=0;i<n;i++){
                hash[nums[i]]++;
            }

            int maxFreq=0;
            for(auto [num,count]:hash){
                maxFreq = max(maxFreq,count);
            }

            int groupsNeeded = n/k;

            return maxFreq <= groupsNeeded;
        }
    };

int main(){
    vector<int> arr = {3,5,2,2};
    cout << Solution().partitionArray(arr,2)<< endl;
    return 0;
}
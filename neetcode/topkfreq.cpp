#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    void printArray(vector<pair<int,int>> num){
        for(auto i:num){
            cout << i.first << ": "<< i.second << endl;
        }
    }

static bool compare(pair<int,int>a,pair<int,int>b){
        return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;

        // count freq
        for(auto i:nums){
            if(mpp.find(i) == mpp.end())mpp[i]=1;
            else mpp[i]++;
        }

        vector<pair<int,int>> sortedMap;
        for(auto i:mpp){
            sortedMap.push_back({i.first,i.second});
        }

        sort(sortedMap.begin(),sortedMap.end(),compare);
        // printArray(sortedMap);
        
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(sortedMap[i].first);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,2,3,3,3};

    vector<int> res = Solution().topKFrequent(nums,2);
    for(auto i:res){
        cout << i << " ";
    }
    cout << endl;
}
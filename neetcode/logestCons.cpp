#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
            set<int> st;
            for(int i=0;i<nums.size();i++){
                st.insert(nums[i]);
            }

            int cnt=1;
            int maxCnt = 1;
            int start = nums[0];
            for(auto i:st){
                if(st.find(i-1) == st.end()){
                    start = i;
                    cnt = 1;
                }
                if(st.find(i-1) != st.end()){
                    cnt++;
                    maxCnt = max(cnt,maxCnt);
                }
            }

            return maxCnt;
    }
};


int main(){
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}
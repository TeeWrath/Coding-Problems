#include<bits/stdc++.h>
using namespace std;

// Most optimized solution
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans(nums1.size(),-1);
            for(int i=0; i< nums1.size(); i++){
                int j=0;
                while(nums2[j] != nums1[i])j++;
                for(int k=j+1; k<nums2.size(); k++){
                    if(nums2[k] > nums2[j]){
                        ans[i] = nums2[k];
                        k = nums2.size();
                    }
                }
            }
    
            return ans;
        }

        // Number of greatest elements to the right
        vector<int> ngeToRight(vector<int>& nums) {
            vector<int> ans(nums.size(),0);
            for(int i=0; i< nums.size(); i++){
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[j] > nums[i])ans[i]++;
                }
            }
    
            return ans;
        }

int main(){
    vector<int> nums = {1,3,4,2};
    vector<int> ans = ngeToRight(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
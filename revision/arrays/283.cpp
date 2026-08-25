#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i =0,j=i+1;
        while(i<n && j < n){
            while(nums[j] != 0 && i < j){
                if(nums[i] == 0){
                    swap(nums[i],nums[j]);
                }
                i++;
            }
            j++;
        }
    }
};

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;

        for(int i=0;i<n;i++){
            if(nums[i] != 0)tmp.push_back(nums[i]);
        }

        int m = n - tmp.size();
        for(int i=0;i<m;i++)tmp.push_back(0);
        for(int i=0;i<n;i++){
            nums[i] = tmp[i];
        }
    }

    int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    moveZeroes(nums);

    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}
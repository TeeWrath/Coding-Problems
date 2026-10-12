#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        map<int,int> mpp;

        for(int i =0;i<n;i++){
            int rem = target - numbers[i];
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem],i+1};
            }
            mpp[numbers[i]] = i+1;
        }

        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0,j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j] > target)j--;
            else if(numbers[i]+numbers[j] < target)i++;
            else return {i+1,j+1};
        }

        return {-1,-1};
    }
};

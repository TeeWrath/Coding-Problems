#include <bits/stdc++.h>
using namespace std;

// Recursive
class SolutionR {
public:
    int binarySearch(int l,int r,vector<int>& nums, int target){
        int n = nums.size();
        if(l>r)return -1;
        int m = l + (r-l)/2;
        if(nums[m] == target)return m;
        if(nums[m]> target) return binarySearch(l,m-1,nums,target);
        else return binarySearch(m+1,r,nums,target);
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(0,nums.size()-1,nums,target);
    }
};

// iterative
class SolutionI {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0,r=n-1;

        while(l<=r){
            int m = l+((r-l)/2);
            if(nums[m]==target)return m;
            else if(nums[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return -1;
    }
};

// upperbound
class SolutionU {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n;
        while(l<r){
            int m = l+((r-l)/2);
            if(nums[m]>target)r=m;
            else l=m+1;
        }

        return (l>0 && nums[l-1]==target)? l-1:-1;
    }
};

// Lowerbound
class SolutionL {
public:
     int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n;
        while(l<r){
            int m = l+((r-l)/2);
            if(nums[m]>=target)r=m;
            else l=m+1;
        }

        return (l<n && nums[l]==target)? l:-1;
    }
};


int main(){
    vector<int> nums ={5,5,5};
    int k; cin>>k;
    int hi= SolutionU().search(nums,k);
    int lo= SolutionL().search(nums,k);
    cout << "Upper bound: " << hi << endl;
    cout << "Lower bound: " << lo << endl;
    cout << "Block of target element " << "[" << lo <<","<< hi << "]" << endl;
}
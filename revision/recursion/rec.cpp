#include <bits/stdc++.h>
using namespace std;

void namePrint(string name,int n){
    if(n==0) return;
    cout << name << endl;
    namePrint(name,n-1);
}

void oneToN(int n, int count){
    if(count == n+1)return;
    cout << count << endl;
    oneToN(n,count+1);
}

int sumOfN(int n,int sum){
    if(n==0)return sum;
    return sumOfN(n-1,sum+n);
}

int factorial(int n){
    if(n==1)return n;
    return factorial(n-1) * n;
}

void countFreq(vector<int> &nums){
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }

    for(auto i:mpp){
        cout << "Frequency of "<< i.first << " is: " << i.second << endl;
    }
}

int main(){
    // int n; cin >> n;
    // // oneToN(n,1);
    vector<int> nums = {1,2,3,5,4,5,4,1,2,23,1,5,4,1,1,1,2,2,6,6,5,4,8,4};
    countFreq(nums);
    // int res = factorial(n);
    // cout << res<<endl;
    return 0;
}
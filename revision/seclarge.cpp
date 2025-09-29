#include<bits/stdc++.h>
using namespace std;

vector<int> seclargesmall(vector<int> &arr, int n){
    if(n<2)return {-1};
    int lr,sl,sm,ss;
    lr=sl=INT_MIN;
    sm=ss=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < sm){
            ss = sm;
            sm = arr[i];
        }
        if(arr[i] < ss && arr[i] > sm)ss = arr[i];
        if(arr[i] > lr){
            sl = lr;
            lr = arr[i];
        }
        if(arr[i] > sl && arr[i] < lr) sl = arr[i];
    }

    if(sl == INT_MIN)sl=-1;
    if(ss == INT_MAX)ss = -1;
    return {sl,ss};
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    vector<int> ans = seclargesmall(arr,arr.size());
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}
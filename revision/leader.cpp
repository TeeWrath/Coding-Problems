#include<bits/stdc++.h>
using namespace std;

void printLeaders(vector<int>& arr){
    int n = arr.size();
    int maxnum = INT_MIN;
    vector<int> ans;

    for(int i=n-1;i>=0;i--){
        if(arr[i] > maxnum){
            ans.push_back(arr[i]);
            maxnum = arr[i];
        }
    }

    for(int i=ans.size()-1;i>=0;i--)cout << ans[i] << ' ';
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 7, 1, 0};
    printLeaders(arr);
    return 0;
}

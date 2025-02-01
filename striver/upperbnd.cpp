#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int> & arr, int k){
    int n = arr.size();
    int ans = n;
    int l = 0; int h = n-1;

    while(l <= h){
        int m = (l+h)/2;

        if(arr[m] > k){
            ans = m;
            h = m-1;
        }
        else l = m +1;
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int res = findCeil(arr,6);
    cout << res;
    return 0;
}
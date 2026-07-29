#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(arr[i]) == mpp.end())mpp[arr[i]]=1;
        else mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;

        // fetch
        if(mpp.find(number) == mpp.end()) cout << 0 << endl;
        else cout << mpp[number] << endl;
    }
    return 0;
}
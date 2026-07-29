#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[nums[i]]+=1; 
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << hash[number] << endl;
    }
    return 0;
}
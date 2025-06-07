#include<bits/stdc++.h>
using namespace std;

vector<int> findMinCoins(int value){
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    int n = coins.size();
    int i = n -1;
    int curVal = value;
    while(curVal > 0 && i>=0){
        if(coins[i] > curVal)i--;
        else{
            curVal = curVal - coins[i];
            ans.push_back(coins[i]);
        }
    }

    return ans;
}

int main(){
    int value; cin >> value;
    vector<int> ans = findMinCoins(value);
    for(auto it:ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
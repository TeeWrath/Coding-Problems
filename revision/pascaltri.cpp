#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// a particular element
int nCr(int row,int col){
    int n = row-1;
    int r = col-1;
    ll ans=1;
    for(int i=0;i<r;i++){
        ans *= (n-i);
        ans /= (i+1);
    }

    return ans;
}

// a particular row
vector<ll> pascalRow(int n){
    vector<ll> res;
        for(int j=0;j<n;j++){
            int val = nCr(n,j+1);
            res.push_back(val);
        }

    return res;
}

// whole triangle
vector<vector<ll>> generate(int n){
    vector<vector<ll>> res;
    for(int i=1;i<=n;i++){
        vector<ll> row = pascalRow(i);
        res.push_back(row);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int row, col;
    cin >> row >> col;
    cout << nCr(row,col) << endl;
    vector<ll> res = pascalRow(row);
    for(auto it: res){
        cout << it<< ' ';
    }
    cout << endl;
    vector<vector<ll>> ans = generate(row);
    for(auto it: ans){
        for(auto itr : it){
            cout << itr << ' ';
        }
        cout << '\n';
    }
    return 0;
}

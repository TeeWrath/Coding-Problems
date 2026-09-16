#include <bits/stdc++.h>
using namespace std;

int nCr(int num, int col){
    int n = num-1;
    int r = col -1;
    int ans = 1;
    for(int i=0;i <r;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> tri;
    

    for(int i=1;i<=numRows;i++){
        vector<int> row;
        for(int j=1;j<=i;j++){
            row.push_back(nCr(i,j));
        }
        tri.push_back(row);
    }

    return tri;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> tri = generate(n);
    for(int i=0;i<tri.size();i++){
        for(int j=0;j<tri[i].size();j++){
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
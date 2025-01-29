#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> & arr){
    int n = arr.size();

    for(int i=0; i<n ;i++){
        cout << arr[i] << " ";
    }
}

// Combinatorics
int nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int pascalNum(int r, int c){
    int res = nCr(r-1,c-1);
    return res;
}

// Naive approach
vector<int> pascalRow(int n){
    vector<int> ans;
    for(int i=1; i<= n; i++){
        ans.push_back(nCr(n-1,i-1));
    }

    return ans;
}

// optimal approach
void pascalRowOp(int n){
    int ans = 1;
    cout<< ans << " ";
    for(int i=1; i< n; i++){
        ans = (ans * (n - i))/ i; // where n = Row number, i = Column number
        cout <<  ans << " ";
    }
}

int main()
{
    // vector<vector<int>> pascal = {};
    // cout << pascalNum(5,3) << endl;
    // vector<int> res = pascalRow(5);
    // printArray(res);
    pascalRowOp(5);
    return 0;
}
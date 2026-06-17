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

int main(){
    int n; cin >> n;
    // oneToN(n,1);

    int res = factorial(n);
    cout << res<<endl;
    return 0;
}
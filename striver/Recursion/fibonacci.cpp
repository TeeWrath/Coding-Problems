#include<bits/stdc++.h>
using namespace std;

int fun(int n){
    if(n<=1) return n;
    int l = fun(n-1);
    cout<< "fun(n-1) called with n-1 as: " << n-1<<" result is: " << l<< endl;
    int m = fun(n-2);
    cout<< "fun(n-2) called with n-2 as: " << n-2<<" result is: " << m<< endl;
    return l + m;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout<<fun(n) << endl;
    return 0;
}

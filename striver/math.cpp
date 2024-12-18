#include <bits/stdc++.h>
using namespace std;

int extractDigits(int n)
{
    return n % 10;
}

int reverseNum(int n)
{
    int num = 0;
    while (n > 0)
    {
        num *= 10;
        if (extractDigits(n) != 0)
            num += extractDigits(n);
        n /= 10;
    }
    return num;
}

void palindromChecker(int n)
{
    if (n == reverseNum(n))
    {
        cout << "True";
        return;
    }
    cout << "false";
}

int greatestCD(int n1, int n2){
    int gcd = 1;
    for(int i = 1; i<= min(n1,n2); i++){
        if(n1%i == 0 && n2%i == 0) gcd = i;
    }
    return gcd;
}

// Optimal Algo to find GCD
int euclidianAlgorithm(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a == 0) return b;
    return a;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    // palindromChecker(n);
    // cout << greatestCD(n1,n2);
    cout << euclidianAlgorithm(n1,n2);
    // cout << min(n1,n2);
    return 0;
}
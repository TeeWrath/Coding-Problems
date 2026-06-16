#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &num){
    for(int i=0;i <num.size();i++){
        cout<< num[i] << " ";
    }
    cout << endl;
}

int countDigits(int n){
    int cnt=0;
    int cpy = n;
    while(cpy > 0){
        cnt++;
        cpy = cpy/10;
    }

    return cnt;
}

int reverseNum(int n){
    int cpy = n;
    int rev = 0;
    while(cpy > 0){
        rev *= 10;
        rev += cpy%10;
        cpy = cpy/10;
    }

    return rev;
}

bool isPalindrome(int n){
    // int rev = reverseNum(n);
    return reverseNum(n) == n;
}

int gcd(int n1,int n2){
    int b = max(n1,n2);
    int s = min(n1,n2);
    int mod = 1;
    while(mod > 0){
        mod = b%s;
        b = s;
        if(mod>0)s = mod;
    }

    return s;
}

bool isArmstrong(int n){
    int sum =0;
    int k = to_string(n).length();
    int cpy = n;
    while(cpy > 0){
        int dig = cpy%10;
        cpy /= 10;
        sum += pow(dig,k);
    }

    return sum == n;
}

int printDivisors(int n){
    int m = sqrt(n);
    vector<int> div;
    for(int i=1;i<= m;i++){
        if(n%i == 0){
            div.push_back(i);
            if(i != n/i) div.push_back(n/i);
        }
    }

    return div.size();

}

bool isPrime(int n){
    int l = printDivisors(n);
    return l == 2;
}

int main(){
    // int n,m; cin >> n;
    // int res = isArmstrong(n);
    // cout << "The number of digits are: "<< res << endl;
    int n; cin >> n;
    int res = isPrime(n);
    cout << res<<endl;
    return 0;
}
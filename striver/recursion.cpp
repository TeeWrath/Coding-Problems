#include<bits/stdc++.h>
using namespace std;

void countRec(int n, int count){
    if(n == count +1) return;
    cout << n << " ";
    n++;
    countRec(n, count);
}

void printName(int i, int n){
    if(i>n) return;
    cout << "Subroto" << " ";
    printName(i+1, n);
}

void printNum(int i, int n){
    if(i>n) return;
    cout << i << " ";
    printNum(i+1,n);
}

void printRevNum(int n){
    if(n == 0) return;
    cout << n << " ";
    printRevNum(n-1);
}

// Using backtracking
void printNumback(int i, int n){
    if(i<1) return;
    printNumback(i-1,n);
    cout << i << " ";
}

void printRevNumback(int i, int n){
    if(i > n) return;
    printRevNumback(i+1,n);
    cout << i << " ";
}

// void sumofNum(int i, int sum){
//     if(i<1){
//         cout << sum;
//         return;
//     }
//     sumofNum(i-1, sum + i);
// }

int sumofNum(int n){
    if(n > 0) return n + sumofNum(n-1);
}

int fac(int n){
    if(n==1) return 1;
    return n*fac(n-1);
}

void printArray(int arr[], int n) {
   cout << "The array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

void reverseArray(int arr[],int l, int r){
    if(l < r){
        swap(arr[l], arr[r]);
        reverseArray(arr, l+1, r-1);
    }
}

bool checkPalindrome(string s, int i){
    if(i >= s.length()/2) return true;
    if(s[i] != s[s.length() - i -1]) return false;
    return checkPalindrome(s, i+1);
}

// Multiple rec calls in single function
int fibonacci(int n){
    if(n<=1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n;
    cin >> n;
    // cout << "The output is:" << endl;
    // countRec(n, count);
    // printName(1, n);
    // printNum(1,n);
    // printRevNum(n);
    // printNumback(n,n);
    // printRevNumback(0,n);
    // cout << sumofNum(n);
    // cout << fac(n);
    // int arr[] = {11,2,15,6,7};
    // reverseArray(arr,0, n-1);
    // printArray(arr,n);
    // string s;
    // cin >> s;
    // cout << checkPalindrome(s,0);
    // if(ans == 1) cout << "true";
    // else cout << "false";
    cout << fibonacci(n);
    return 0;
}
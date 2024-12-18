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

int main(){
    int n;
    cin >> n;
    cout << "The output is:" << endl;
    // countRec(n, count);
    printName(1, n);
    return 0;
}
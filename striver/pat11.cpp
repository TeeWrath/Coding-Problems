#include<iostream>
using namespace std;

void printPattern(int n){
    int start = 1;
    for(int i=1; i<=n; i++){

        // Even row - first number is zero
        if(i%2 == 0) start = 0;
        // Odd row - first number is one
        else start = 1;

        for(int j=1; j<=i; j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}
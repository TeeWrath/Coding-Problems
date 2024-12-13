#include<iostream>
using namespace std;

void printPattern(int n){
    char ch = 'A';
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= i; j++){
            cout<< ch << " ";
        }
        cout << endl;
        ch += 1;
    }
}

int main(){
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}
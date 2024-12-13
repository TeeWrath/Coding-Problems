#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i = 1; i<=n; i++){
        char ch = 'A';
        for(int j = 1; j<= n -i + 1; j++){
            cout<< ch << " ";
            ch += 1;
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
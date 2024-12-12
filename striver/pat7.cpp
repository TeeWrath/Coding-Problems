#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=1; i<=n; i++){
        // Spaces
        for(int j=1; j<= n - i; j++){
            cout << " ";
        }

        // Stars
        for(int k = 1; k <= (2*i) - 1; k++){
            cout << "*";
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
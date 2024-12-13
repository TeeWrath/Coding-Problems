#include<iostream>
using namespace std;

void printPattern(int n){
    // Number of rows will be 2*N - 1
    for(int i=1; i<= (2*n) - 1; i++){
        // Number of stars will be equal to row number till row <= N
        int stars = i;

        // Number of stars become 2*N - row number, after row number is > N, 
        // this produces decreasing star numbers
        if(i>n) stars = 2*n - i;

        // Loop to print stars
        for(int j=1; j<= stars; j++){
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
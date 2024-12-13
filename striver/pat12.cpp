#include<iostream>
using namespace std;

void printPattern(int n){

    // Initial number of spaces for first row
    // this will go on to decrease by 2 for each row
    int spaces = 2*(n - 1);

    for(int i = 1; i<= n; i++){
        
        // left side of number
        for(int j=1; j<=i; j++){
            cout << j;
        }

        // print the spaces
        for(int j=1; j<=spaces; j++){
            cout << " ";
        }

        // right side of numbers
        for(int j=i; j>=1; j--){
            cout << j;
        }
        
        // next line
        cout << endl;

        // decreasing number of spaces per row
        spaces -= 2;
    }
}

int main(){
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void printArray(int arr[], int n) {
   cout << "The array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void createHashtable(int arr[], int n, int hash[]){
    for(int i =0; i<n; i++){
        hash[arr[i]]++;
    }
}

void printMax(int arr[],int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > max) max = i;
    }
    cout << "Max frequency element is: " << max;
}

int main(){
    int arr[] = {1,3,3,1,3};
    // int n;
    int hash[9];
    // cin >> n;
    for(int i=0; i<9; i++){
        hash[i] = 0;
    }
    createHashtable(arr,5, hash);
    printArray(hash, 9);
    printMax(hash,9);
    return 0;
}
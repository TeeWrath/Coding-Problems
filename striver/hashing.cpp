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

void charHash(string s, int hash[]){
    for(int i=0; i<s.length() ;i++){
        hash[s[i] - 'a']++;
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
    // int arr[] = {1,3,3,1,3};
    // int n;
    // int hash[26];
    // cin >> n;
    // for(int i=0; i<26; i++){
    //     hash[i] = 0;
    // }
    // createHashtable(arr,5, hash);
    // printArray(hash, 9);
    // printMax(hash,9);
    // string s;
    // cin >> s;
    // charHash(s,hash);
    // printArray(hash,26);
    int n;
    cout << "Enter the size of input array;" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements for intput array:" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    map<int, int> mpp;
    for(int i=0 ;i < n; i++){
        mpp[arr[i]]++;
    }

    int q;
    cout << "Enter the number of elements whose frequency you wish to find:" << endl;
    cin >> q;
    while(q--){
        int number;
        cout << "Enter the number jiski freq chiye:" << endl;
        cin >> number;
        cout << mpp[number] << endl;
    }
    cout << "Program khatam bro :)";
    return 0;
}
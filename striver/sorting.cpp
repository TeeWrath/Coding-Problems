#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
   cout << "The array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void bubbleSort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int didSwap =0;
        for(int j=0; j<=i-1;j++){
            if(arr[j+1]<arr[j]) {
                swap(arr[j], arr[j+1]);
                didSwap++;
            }
        }
        if(didSwap == 0)break;
    }
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n ; i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

void merge(int arr[], int l, int mid, int h){
    vector<int> temp;
    int left = l;
    int right = mid+1;
    while(left <= mid && right <= h){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= h){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i= l; i<=h ; i++){
        arr[i] = temp[i-l];
    }
}

void mergeSort(int arr[], int l, int h){
    if(l >= h) return;
    int mid = (l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr, mid+1, h);
    merge(arr,l, mid, h);
}

int main(){
    int arr[] = {52 ,14 ,46 ,13 ,9 ,7 ,2 ,100 ,83};
    cout << "Before sorting ";
    printArray(arr,9);
    // selectionSort(arr,9);
    // bubbleSort(arr,9);
    // insertionSort(arr,9);
    mergeSort(arr,0, 8);
    printArray(arr,9);
    return 0;
}
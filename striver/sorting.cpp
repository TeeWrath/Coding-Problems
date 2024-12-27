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

void recBubbleSort(int arr[], int n){
        int didSwap =0;
        if(n == 1) return;
        for(int j=0; j<=n-2;j++){
            if(arr[j+1]<arr[j]) {
                swap(arr[j], arr[j+1]);
                didSwap++;
            }
        }
        if(didSwap == 0)return;
        recBubbleSort(arr,n-1);
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

void recInsertionSort(int arr[], int n, int i){
    // Base case
    if(i==n) return;

        // same thing as insertion algo
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }

    // recursively moving the outer loop
    recInsertionSort(arr,n,i+1);
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

int findPartition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i<j){
        while(arr[i] <= pivot && i<=h-1){
            i++;
        }
        while(arr[j] > pivot && j >= l+ 1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h){
    if(l<h){
        int pIndex = findPartition(arr,l,h);
        quickSort(arr,l,pIndex-1);
        quickSort(arr,pIndex+1,h);
    }
}

int main(){
    int arr[] = {52 ,14 ,46 ,13 ,9 ,7 ,2 ,100 ,83};
    // int arr[] = {5,4,3,2,1};
    cout << "Before sorting ";
    printArray(arr,9);
    // selectionSort(arr,9);
    // bubbleSort(arr,9);
    // insertionSort(arr,9);
    // mergeSort(arr,0, 8);
    // quickSort(arr,0,8);
    // recBubbleSort(arr,9);
    recInsertionSort(arr,9,0);
    printArray(arr,9);
    return 0;
}
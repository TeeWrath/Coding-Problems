#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partitionIndex(vector<int> &arr,int low,int high){
    int i=low, j = high,pivot = arr[low];
    while(i<j){
        while(arr[i] <= pivot && i<=high-1)i++;
        while(arr[j] > pivot && j>=low+1)j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr,int low,int high){
    
    if(low<high){
        int pivot = partitionIndex(arr,low,high);

        quickSort(arr,low,pivot-1);

        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        // int t; cin >> t;
        // arr.push_back(t);
        cin >> arr[i];
    }

    printArray(arr);

    quickSort(arr,0,n-1);
    
    printArray(arr);
    return 0;
}
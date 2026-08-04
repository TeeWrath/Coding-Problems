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

void merge(vector<int> & arr, int low,int mid, int high){
    vector<int> tmp;
    int left = low,right=mid+1;

    while(left<=mid && right <=high){
        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }else{
            tmp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        tmp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        tmp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = tmp[i-low];
    }
}

void mergeSort(vector<int> & arr, int low, int high){
    if(low>=high)return;

    int mid = (low+high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid, high);
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

    mergeSort(arr,0,n-1);
    
    printArray(arr);
    return 0;
}
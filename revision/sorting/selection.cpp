#include <bits/stdc++.h>
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

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<n;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[mini]) mini = j;
        }

        int tmp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = tmp;
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

    selectionSort(arr);

    printArray(arr);
    return 0;
}
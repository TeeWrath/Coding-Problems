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

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
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

    insertionSort(arr);
    
    printArray(arr);
    return 0;
}
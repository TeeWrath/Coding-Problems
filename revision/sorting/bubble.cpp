#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    int cntMoves = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        bool didSwap = 0;
        cntMoves++;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            cout << "Total moves: " << cntMoves << endl;
            break;
        }
    }
}

void printArray(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    bubbleSort(arr);

    printArray(arr);
    return 0;
}
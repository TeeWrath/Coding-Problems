#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printTwoDArray(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    // int m;
    // cout << "enter m: ";
    // cin >> m;
    cout << endl;
    vector<vector<int>> matrix(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter value to be inserted at position: " << "(" << i << "," << j << ") : ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix you entered: " << endl;
    printTwoDArray(matrix);

    rotate(matrix);

    cout << "Matrix after rotating: " << endl;
    printTwoDArray(matrix);

    return 0;
}
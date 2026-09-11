#include <bits/stdc++.h>
using namespace std;

// brute
void setZeroesBrute(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> mark(n, vector<bool>(m, false));

    // marking the zeroes
    for (int i = 0; i < matrix.size(); i++)
    {

        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                mark[i][j] = true;
            }
        }
    }

    // set zeroes now
    for (int i = 0; i < mark.size(); i++)
    {
        for (int j = 0; j < mark[i].size(); j++)
        {
            if (mark[i][j] == true)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = 0;
                }

                for (int k = 0; k < m; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = 0;
                }
            }
        }
    }
}

// better
void setZeroesBetter(vector<vector<int>> &matrix)
{
    // rows - n, columns - m
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> row(n, false);
    vector<bool> col(m, false);

    // marking the zeroes
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // set zeroes now
    for (int i = 0; i < n; i++)
    {
        if (row[i] == true)
        {
            for (int k = 0; k < m; k++)
            {
                if (matrix[i][k] != 0)
                    matrix[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (col[i] == true)
        {
            for (int k = 0; k < n; k++)
            {
                if (matrix[k][i] != 0)
                    matrix[k][i] = 0;
            }
        }
    }
}

// optimum
void setZeroes(vector<vector<int>> &matrix)
{
    // rows - n, columns - m
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 1;
    int col = 1;

    // marking the zeroes
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // if first row
                if (i == 0)
                    row = 0;
                if (j == 0)
                    col = 0;
                if (i != 0)
                    matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
            }
        }
    }

    // set zeroes now
    // columns except first
    for (int j = 1; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int k = 0; k < n; k++)
            {
                if (matrix[k][j] != 0)
                    matrix[k][j] = 0;
            }
        }
    }

    // rows except first
    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int k = 0; k < m; k++)
            {
                if (matrix[i][k] != 0)
                    matrix[i][k] = 0;
            }
        }
    }

    // first row
    if (row == 0)
    {
        for (int k = 0; k < m; k++)
        {
            if (matrix[0][k] != 0)
                matrix[0][k] = 0;
        }
    }

    // first column
    if (col == 0)
    {
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][0] != 0)
                matrix[k][0] = 0;
        }
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
    int m;
    cout << "enter m: ";
    cin >> m;
    cout << endl;
    vector<vector<int>> matrix(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter value to be inserted at position: " << "(" << i << "," << j << ") : ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix you entered: " << endl;
    printTwoDArray(matrix);

    setZeroes(matrix);

    cout << "Matrix after setting zeroes: " << endl;
    printTwoDArray(matrix);

    return 0;
}
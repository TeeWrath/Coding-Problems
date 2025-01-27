#include<bits/stdc++.h>
using namespace std;


void printMatrix(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << "";
        }
        cout << endl;
    }
}


// Brute force
class Solution {
public:
    void markCol(int col, vector<vector<int>> & matrix){
        int m = matrix.size();
        
        for(int i=0; i<m ;i++){
            if(matrix[i][col] != 0){
                matrix[i][col] = INT_MIN;
            }
        }
    }

    void markRow(int row, vector<vector<int>> & matrix){
        int n = matrix[0].size();
        
        for(int i=0; i<n ;i++){
            if(matrix[row][i] != 0){
                matrix[row][i] = INT_MIN;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    markCol(j,matrix);
                    markRow(i,matrix);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == INT_MIN){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}
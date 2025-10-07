#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size(); // rows
            int m = matrix[0].size(); // cols
            int col0 = 1;

            // mark rows and columns that have to be turned to zero
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        // mark rows
                        matrix[i][0]=0;

                        // mark columns
                        if(j!=0)matrix[0][j]=0;
                        else col0 = 0;
                    }
                }
            }

            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(matrix[i][j]!=0){
                        if(matrix[i][0] == 0 || matrix[0][j]==0)matrix[i][j]=0;
                    }
                }
            }

            // for the first rows and columns
            if(matrix[0][0]==0){
                for(int j=0;j<m;j++)matrix[0][j]=0;
            }

            if(col0==0){
                for(int i=0;i<n;i++)matrix[i][0]=0;
            }
        }
    };
    

int main(int argc, char const *argv[])
{
    int n,m; 
    cout << "enter n: ";
    cin>> n;
    cout << "enter m: ";
    cin >> m;
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << "enter"<< i << j<< "th element: ";
            int ele; cin>>ele;
            matrix[i].push_back(ele);
            cout << endl;
        }
    }

    Solution().setZeroes(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << ' ';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();

            // transpose
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }

            for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
    };

int main(int argc, char const *argv[])
{
    int n;
    cout << "enter n: ";
    cin>> n;
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "enter"<< i << j<< "th element: ";
            int ele; cin>>ele;
            matrix[i].push_back(ele);
            cout << endl;
        }
    }

    Solution().rotate(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << ' ';
        }
    }
    return 0;
}

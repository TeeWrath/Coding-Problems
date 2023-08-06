class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int col1 = 1;

        // Traversing through matrix and marking first columns and rows accordingly
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    if(j !=0){
                        matrix[i][0] =0;
                        matrix[0][j] =0;
                    }
                    else{
                        col1 =0;
                    }
                }
            }
        }

        // marking all the cells accordingly except the first row and column
        for(int i=1 ; i<n; i++){
            for(int j=1 ; j<m ; j++){
                if(matrix[0][j]==0 || matrix[i][0] ==0){
                    matrix[i][j] =0;
                }
            }
        }

        // marking first row
        if(matrix[0][0] ==0){
            for(int j=0; j<m ; j++){
                matrix[0][j] = 0;
            }
        }

        // checking col1 value
        if(col1 == 0){
            for(int i=0; i<n ; i++){
                matrix[i][0] = 0;
            }
        }
    }
}
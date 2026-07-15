class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m*n -1;
        while( low <= high ) {
           int mid = low + (high-low)/2;
           int r =  ( mid / n);
           int c = ( mid % n );
           int elmt = matrix[r][c]; 
           if( elmt > target ) high = mid-1;
           else if (elmt < target) low = mid +1;
           else return true;
        }
        return false;
    }
};

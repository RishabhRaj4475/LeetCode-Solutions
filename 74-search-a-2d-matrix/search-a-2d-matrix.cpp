class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0 , high = n - 1;
        int idxRow = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if( matrix[mid][0] <= target){
                idxRow = max(idxRow , mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if( idxRow == -1) return false;

        low = 0 , high = m-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[idxRow][mid] == target){
                return true;
            } else if( matrix[idxRow][mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        // Start at the top-right corner
        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true; 
            } else if (matrix[row][col] > target) {
                col--; // Target must be in a left column
            } else {
                row++; // Target must be in a lower row
            }
        }

        return false;
    }
};

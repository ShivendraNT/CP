class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=m-1;
        int r=-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                r=mid;
                break;
            }
            else if(target>matrix[mid][0]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(r==-1){
            return false;
        }
        vector<int> row=matrix[r];
        left=0;
        right=n-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(row[mid]==target){
                return true;
            }
            else if(row[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;
    }
};

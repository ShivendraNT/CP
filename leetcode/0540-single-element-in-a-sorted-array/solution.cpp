class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0];
        }
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
    (mid == n - 1 || nums[mid] != nums[mid + 1])) {
    return nums[mid];
}
            else if (nums[mid]==nums[mid-1]){
                if (mid%2==0){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if (mid%2==0){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return 0;
    }
};

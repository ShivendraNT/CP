class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size()-1;
        int right=nums.size()-1;
        int left=0;
        int ans=nums[0]; 
        while(right>=left){
            int mid=(right-left)/2+left;
            ans=min(ans,nums[mid]);
            if(nums[left]==nums[right]){
                left++;
                right--;
                continue;
            }
            if(nums[mid]<=nums[right]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};

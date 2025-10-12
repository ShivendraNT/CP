class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total,curr_sum;
        total=curr_sum=nums[0];
        nums.erase(nums.begin());
        for (int i:nums){
            curr_sum=max(i,curr_sum+i);
            total=max(total,curr_sum);
        }
        return total;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int x : nums) totalSum += x;
        
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        
        vector<bool> prev(target + 1, false);
        
        prev[0] = true;
        
        if (nums[0] <= target) prev[nums[0]] = true;
        
        for(int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true; 
            
            for(int j = 1; j <= target; j++) {
                bool notTake = prev[j];
                
                bool take = false;
                if(nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};

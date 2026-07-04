class Solution {
private:
    int solveLinearDP(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int loot = nums[i] + dp[i-2];
            int skip = dp[i-1];
            
            dp[i] = max(loot, skip);
        }
        
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> firstHouseIncluded;
        vector<int> lastHouseIncluded;
        
        for (int i = 0; i < n; i++) {
            if (i != n - 1) firstHouseIncluded.push_back(nums[i]);
            if (i != 0)     lastHouseIncluded.push_back(nums[i]); 
        }
        
        int ans1 = solveLinearDP(firstHouseIncluded);
        int ans2 = solveLinearDP(lastHouseIncluded);
        
        return max(ans1, ans2);
    }
};

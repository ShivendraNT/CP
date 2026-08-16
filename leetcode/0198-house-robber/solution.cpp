class Solution {
public:
    /*
    int f(vector<int>&nums,int house,int n,vector<int>&memo){
        if(house>=n){
            return 0;
        }
        if(memo[house]!=-1){
            return memo[house];
        }
        // choose to rob this house
        return max(nums[house]+f(nums,house+2,n,memo),f(nums,house+1,n,memo));
    }
    */
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2);
        dp[n+1]=0;
        dp[n]=0;
        for(int house=n-1;house>=0;house--){
            dp[house]=max(nums[house]+dp[house+2],dp[house+1]);
        }
        return dp[0];
    }
};

class Solution {
public:
    /*
    bool f(vector<int>&nums,int i,int sum,int currsum,vector<vector<int>>& memo,int n){
        if(currsum==sum ){
            return true;
        }
        if(currsum>sum || i>=n){
            return false;
        }
        if(memo[i][currsum]!=-1){
            return (bool)memo[i][currsum];
        }
        bool take=f(nums,i+1,sum,currsum+nums[i],memo,n);
        bool nottake=f(nums,i+1,sum,currsum,memo,n);
        memo[i][currsum]=(int)(take||nottake);
        return take||nottake;
    }
    */
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        sum/=2;
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        dp[n][0] = true;
        for(int i=n-1;i>=0;i--){
            for(int s=0;s<=sum;s++){
                dp[i][s]=dp[i+1][s];
                if(s >= nums[i]) dp[i][s] = dp[i][s] || dp[i+1][s - nums[i]];
            }
        }
        return dp[0][sum];
    }
};

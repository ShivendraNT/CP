class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n,0);
        int maxtheft=0;
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=0;i<n;i++){
            for(int j=i-2;j>=0;j--){
                dp[i]=max(dp[i],nums[i]+dp[j]);
            }
            maxtheft=max(maxtheft,dp[i]);
        }
        return maxtheft;
    }
};

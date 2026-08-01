class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        for(int i=n-1;i>=0;i--){
            dp[i] = nums[i];
            for(int j=i+1;j<n;j++){
                int take_left=nums[i]-dp[j];
                int take_right=nums[j]-dp[j - 1];
                dp[j]=max(take_left,take_right);
            }
        }
        return dp[n-1]>=0;
    }
};

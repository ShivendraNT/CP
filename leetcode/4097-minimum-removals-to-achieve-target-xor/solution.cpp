class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int total = 0;
        for(int x : nums) total ^= x;
        int need = total ^ target;

        const int MAXX = 1 << 14;          
        vector<int> dp(MAXX, INT_MAX);
        dp[0] = 0;

        for(int v : nums){
            vector<int> ndp = dp;       
            for(int j = 0; j < MAXX; j++)
                if(dp[j] != INT_MAX)
                    ndp[j ^ v] = min(ndp[j ^ v], dp[j] + 1);
            dp = ndp;
        }
        return dp[need] == INT_MAX ? -1 : dp[need];
    }   
};

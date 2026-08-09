class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> suffix(n+1,0);
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        for(int i=n-1;i>=0;i--){
            suffix[i]=piles[i]+suffix[i+1];
        }
        for(int i=n-1;i>=0;i--){
            for(int M=1;M<=n;M++){
                if(2*M>=n-i){
                    dp[i][M]=suffix[i];
                    continue;
                }
                long long mini=LLONG_MAX;
                for(int X=1;X<=2*M;X++){
                    mini=min(mini,dp[i+X][max(X,M)]);
                }
                dp[i][M]=suffix[i]-mini;
            }
        }
        return dp[0][1];
    }
};

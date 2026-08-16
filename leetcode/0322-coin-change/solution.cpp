class Solution {
public:
    int INF=2e8;
    /*
    int f(vector<int>&coins,int amount,vector<int>&memo){
        if(amount==0){
            return 0;
        }
        else if(amount<0){
            return INF;
        }
        if(memo[amount]!=-1){
            return memo[amount];
        }
        int minreq=INF;
        for(int i=0;i<coins.size();i++){
            minreq=min(minreq,1+f(coins,amount-coins[i],memo));
        }
        return memo[amount]=minreq;
    }
    */
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INF);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]<0){
                    continue;
                }
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return (dp[amount]==INF)?-1:dp[amount];
    }
};

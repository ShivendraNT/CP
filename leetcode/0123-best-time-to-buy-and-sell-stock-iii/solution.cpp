class Solution {
public:
/*
    int f(int i,int holding,int tleft,vector<int>&prices,int n,vector<vector<vector<int>>>&memo){
        if(i==n || tleft<=0){
            return 0;
        }
        if(memo[i][holding][tleft]!=-1){
            return memo[i][holding][tleft];
        }
        if(holding==0){
            return memo[i][holding][tleft]=max(-prices[i]+f(i+1,1,tleft,prices,n,memo),f(i+1,0,tleft,prices,n,memo));
        }
        else{
            return memo[i][holding][tleft]=max(prices[i]+f(i+1,0,tleft-1,prices,n,memo),f(i+1,1,tleft,prices,n,memo));
        }
        return -1;
    }
    */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int holding=0;holding<2;holding++){
                for(int tleft=1;tleft<3;tleft++){
                    if(holding==0){
                        dp[i][holding][tleft]=max(-prices[i]+dp[i+1][1][tleft],dp[i+1][0][tleft]);
                    }
                    else{
                        dp[i][holding][tleft]=max(prices[i]+dp[i+1][0][tleft-1],dp[i+1][1][tleft]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};

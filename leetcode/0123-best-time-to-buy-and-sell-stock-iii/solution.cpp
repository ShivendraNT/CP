class Solution {
public:
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,2,prices,n,memo);
    }
};

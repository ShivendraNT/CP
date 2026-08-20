class Solution {
public:
    /*
    int f(string & text1,string & text2,int i,int j,int n,int m,vector<vector<int>>& memo){
        if(i>=n || j>=m){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int lis=0;
        if(text1[i]==text2[j]){
            lis=max(lis,1+f(text1,text2,i+1,j+1,n,m,memo));
        }
        lis=max(lis,f(text1,text2,i,j+1,n,m,memo));
        lis=max(lis,f(text1,text2,i+1,j,n,m,memo)); 
        return memo[i][j]=lis;
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                dp[i][j]=max({dp[i][j],dp[i][j+1],dp[i+1][j]});
            }
        }
        return dp[0][0];
    }
};

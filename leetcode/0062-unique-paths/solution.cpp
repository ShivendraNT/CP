class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        int drow[]={-1,0};
        int dcol[]={0,-1};
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) continue;
                int ans=0;
                for(int k=0;k<2;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row>=0 && col>=0){
                        ans+=dp[row][col];
                    }
                }
                dp[i][j]=ans;
            }
        }
        return dp[m-1][n-1];
    }
};

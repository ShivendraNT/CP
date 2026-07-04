class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=1;
        int drow[]={-1,0};
        int dcol[]={0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
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
        return dp[n-1][m-1];
    }
};

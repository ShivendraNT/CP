class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=grid[0][0];
        int drow[]={-1,0};
        int dcol[]={0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int ans=INT_MAX;
                for(int k=0;k<2;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row>=0 && col>=0){
                        ans=min(dp[row][col],ans);
                    }
                }
                dp[i][j]=ans+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>> dpsum(n,vector<int>(n,0));
        vector<vector<int>> dppath(n,vector<int>(n,0));
        dpsum[n-1][n-1]=0;
        dppath[n-1][n-1]=1;
        int drow[]={1,0,1};
        int dcol[]={0,1,1};
        int MOD = 1e9 + 7;

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1 && j==n-1) continue;
                if(board[i][j]=='X'){
                    continue;
                }
                int ans=0;
                int paths=0;
                for(int k=0;k<3;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row<n && col<n && dppath[row][col] > 0){
                        if(dpsum[row][col]>ans){
                            ans=dpsum[row][col];
                            paths = dppath[row][col];
                        }else if(dpsum[row][col] == ans) {
                            paths = (paths + dppath[row][col]) % MOD;
                        }
                    }
                }
                if(paths == 0) continue;
                if(board[i][j]=='E'){
                    return {ans,paths};
                }
                dpsum[i][j]=ans+(board[i][j]-'0');
                dppath[i][j]=paths;
            }
        }
        return {0,0};
    }
};

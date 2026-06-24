class Solution {
public:
    int search(vector<vector<int>>& board,vector<vector<int>> & vis,int i,int j,int n,int m){
        int ans=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        bool boundary=false;
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            ans++;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(board[nrow][ncol]==1&&!vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
                else{
                    boundary=true;
                }
            }
        }
        if(boundary) return 0;
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    ans+=search(grid,vis,i,j,n,m);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    void search(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j,int n,int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=row+drow[k];
                int ncol=col+dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    search(grid,vis,i,j,n,m);
                }
            }
        }
        return ans;
    }
};

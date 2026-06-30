class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) dist[i][j]=1e9;
                else dist[i][j]=-1;
            }
        }
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.top();
            int row=it.second.first;
            int col=it.second.second;
            int wt=it.first;
            q.pop();
            if(wt>dist[row][col]) continue;

            // Checking all with common edge
            int drow[]={-1,0,1,0,-1,-1,1,1};
            int dcol[]={0,-1,0,1,-1,1,-1,1};
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dist[nrow][ncol]>wt+1){
                    dist[nrow][ncol]=wt+1;
                    q.push({wt+1,{nrow,ncol}});
                }
            }
        } 
        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];
    }
};

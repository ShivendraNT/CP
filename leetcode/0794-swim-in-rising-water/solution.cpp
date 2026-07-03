class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!pq.empty()){
            int t=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==n-1){
                return t;
            }
            int drow[]={-1,0,1,0};
            int dcol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n &&!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({max(t,grid[nrow][ncol]),{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};

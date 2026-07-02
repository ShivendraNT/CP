class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1) health--;
        if(health<=0) return false;

        priority_queue<pair<int, pair<int,int>>> q;
        q.push({health, {0, 0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.top().second.first;
            int col=q.top().second.second;
            int h=q.top().first;
            q.pop();
            if (grid[row][col] == 2) continue; 
            grid[row][col]=2;
            if(row==n-1 && col==m-1) return true;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    if(grid[nrow][ncol]==1 && h>1){
                        q.push({h-1,{nrow,ncol}});
                    }
                    else if(grid[nrow][ncol]==0){
                        q.push({h,{nrow,ncol}});
                    }
                }
            }
        }
        return false;
    }
};

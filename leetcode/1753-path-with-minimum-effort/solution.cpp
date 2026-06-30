class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        while(!q.empty()){
            auto it=q.top();
            int row=it.second.first;
            int col=it.second.second;
            int wt=it.first;
            q.pop();
            if(wt>dist[row][col]) continue;

            // Checking all with common edge
            int drow[]={-1,0,1,0};
            int dcol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int diff=max(wt,abs(heights[row][col]-heights[nrow][ncol]));
                    if(dist[nrow][ncol]>diff){
                        dist[nrow][ncol]=diff;
                        q.push({diff,{nrow,ncol}});
                    }

                }
            }
        } 
        return dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1];
    }
};

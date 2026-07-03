class DisjointSet {
    
public:
    vector<int> rank,parent,size;

    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUparent(parent[node]);
    }

    bool find(int u, int v) {
        return findUparent(u)==findUparent(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        // Connecting components
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                        int node=row*n + col;
                        int nnode=nrow*n + ncol;
                        ds.unionBySize(node,nnode);
                    }
                }
            }
        }
        int ans=0;
        // Convert every zero to one
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                set<int> comp;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                        comp.insert(ds.findUparent(nrow*n+ncol));
                    }
                }
                int totalsize=0;
                for(auto it:comp){
                    totalsize+=ds.size[it];
                }
                ans=max(ans,totalsize+1);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++){
            ans=max(ans,ds.size[ds.findUparent(cellno)]);
        }
        return ans;
    }
};

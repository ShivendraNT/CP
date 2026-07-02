class DisjointSet {
    
public:
    vector<int> parent,size;
    DisjointSet(int n) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras=0;
        for(auto it: connections){
            int u=it[0];
            int v=it[1];
            if(ds.find(u,v)) extras++;
            else{
                ds.unionBySize(u,v);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) c++;
        }
        if(extras>=c-1){
            return c-1;
        }
        return -1;

    }
};

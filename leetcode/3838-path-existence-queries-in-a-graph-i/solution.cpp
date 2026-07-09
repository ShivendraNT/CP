class Solution {
public:
class DisjointSet {
    vector<int>parent,size;
public:
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

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i = 0; i < n - 1; i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                ds.unionBySize(i, i + 1);
            }
        }
        int m=queries.size();
        vector<bool> ans;
        for(int i=0;i<m;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(ds.findUparent(u)==ds.findUparent(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

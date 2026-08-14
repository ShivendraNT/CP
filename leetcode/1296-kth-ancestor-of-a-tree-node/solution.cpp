class TreeAncestor {
public:
    const int LOG=20;
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int>& parent) {
        up.assign(n,vector<int>(LOG,-1));
        for(int u=0;u<n;u++){
            up[u][0]=parent[u];
        }
        for(int j=1;j<LOG;j++){
            for(int u=0;u<n;u++){
                int mid=up[u][j-1];
                up[u][j]=(mid==-1)?-1:up[mid][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<LOG && node!=-1;j++){
            if(k&(1<<j)){
                node=up[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

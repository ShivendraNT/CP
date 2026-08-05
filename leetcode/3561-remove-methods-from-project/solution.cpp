class Solution {
public:
    void dfs(int n, int node,vector<vector<int>> & adj, vector<int>&vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(n,it,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0);
        dfs(n,k,adj,vis);
        for (auto& edge : invocations) {
            int u = edge[0], v = edge[1];
            if (!vis[u] && vis[v]) {
                vector<int> all(n);
                for (int i = 0; i < n; i++) all[i] = i;
                return all;
            }
        }
        vector<int> ans;
        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                ans.push_back(node);
            }
        }

        return ans;
    }
};

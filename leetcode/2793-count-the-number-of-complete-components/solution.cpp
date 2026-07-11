class Solution {
public:
    bool bfs(vector<vector<int>> & adj, vector<int> &vis,int node){
        int numnode=0;
        queue<int> q;
        q.push(node);
        vis[node]=1;
        int edges=0;
        while(!q.empty()){
            int currnode=q.front();
            q.pop();
            numnode++;
            edges += adj[currnode].size();
            for(auto it:adj[currnode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        if(edges==((numnode*(numnode-1)))){
            return true;
        }
        return false;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(adj,vis,i)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

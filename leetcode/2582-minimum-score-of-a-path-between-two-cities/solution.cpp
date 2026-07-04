class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        queue<int> q;
        vector<bool> vis(n + 1, false);
        
        q.push(1);
        vis[1] = true;
        
        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                ans = min(ans, wt);

                if (!vis[adjNode]) {
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }
};

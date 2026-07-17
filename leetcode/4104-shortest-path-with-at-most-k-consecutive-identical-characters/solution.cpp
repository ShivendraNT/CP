class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 1}});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto topElement = pq.top();
            pq.pop();

            int wt = topElement.first;
            int node = topElement.second.first;
            int cnt = topElement.second.second;

            if (node == n - 1) return wt;

            if (wt > dist[node][cnt]) continue;

            for (const auto& it : adj[node]) {
                int nextnode = it.first;
                int nextwt = it.second;
                
                int next_cnt = (labels[node] == labels[nextnode]) ? cnt + 1 : 1;


                if (next_cnt > k) continue;

                if (wt + nextwt < dist[nextnode][next_cnt]) {
                    dist[nextnode][next_cnt] = wt + nextwt;
                    pq.push({wt + nextwt, {nextnode, next_cnt}});
                }
            }
        }
        return -1;
    }
};

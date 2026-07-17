class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        if (n == 1) return baseTime[0];

        vector<int> parent(n, -1);
        vector<int> outDegree(n, 0); 
        
        for (const auto& edge : edges) {
            int u = edge[0]; 
            int v = edge[1]; 
            parent[v] = u;
            outDegree[u]++;
        }

        vector<long long> min_child(n, LLONG_MAX);
        vector<long long> max_child(n, -1);
        vector<long long> finish(n, 0);

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                finish[i] = baseTime[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int p = parent[curr];
            if (p != -1) {
                min_child[p] = min(min_child[p], finish[curr]);
                max_child[p] = max(max_child[p], finish[curr]);
                
                outDegree[p]--;
                if (outDegree[p] == 0) {
                    long long earliest = min_child[p];
                    long long latest = max_child[p];
                    long long ownDuration = (latest - earliest) + baseTime[p];
                    finish[p] = latest + ownDuration;
                    
                    q.push(p);
                }
            }
        }

        return finish[0];
    }
};

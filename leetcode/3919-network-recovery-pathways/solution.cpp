class Solution {
public:
    bool isFeasible(vector<vector<pair<int,int>>>& adj, vector<bool>& online, int n, long long k, int minWt){
        if(!online[0] || !online[n-1]) return false;

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;
            if(node == n-1) return d <= k; 

            for(int j=0; j<adj[node].size(); j++){
                int nextNode = adj[node][j].first;
                int wt = adj[node][j].second;

                if(wt < minWt) continue;      
                if(!online[nextNode]) continue;

                long long newDist = d + wt;
                if(newDist < dist[nextNode] && newDist <= k){
                    dist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        return (dist[n-1] != LLONG_MAX) && (dist[n-1] <= k);
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int maxWt = 0;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            if(wt > maxWt) maxWt = wt;
        }

        int lo = 0, hi = maxWt, ans = -1;  

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(isFeasible(adj, online, n, k, mid)){
                ans = mid;      
                lo = mid + 1;
            } else {
                hi = mid - 1;   
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0,0});
        long long mod = 1e9 + 7;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while(!q.empty()){
            long long d=q.top().first;
            int node=q.top().second;
            q.pop();
            if(d>dist[node]) continue;

            for(auto it: adj[node]){
                int adjnode=it.first;
                long long adjwt=it.second;
                if(dist[adjnode]>d+adjwt){
                    dist[adjnode]=d+adjwt;
                    ways[adjnode] = ways[node];
                    q.push({dist[adjnode],adjnode});
                }
                else if(dist[adjnode] == d + adjwt){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};

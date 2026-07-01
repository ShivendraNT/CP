class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u-1].push_back({v-1,wt});
        }
        vector<int> vis(n, 0);
        int visited_count = 0;

        vector<int> time(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k-1});
        time[k-1]=0;
        while(!q.empty()){
            int t=q.top().first;
            int node=q.top().second;
            q.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            visited_count++;

            if(visited_count == n) return t;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjtime=it.second;
                if(time[adjnode]>time[node]+adjtime){
                    time[adjnode]=time[node]+adjtime;
                    q.push({time[adjnode],adjnode});
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) q.push(i);
            else continue;
            vis[i]=1;
            ans++;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j = 0; j < n; j++){
                    if(isConnected[node][j] == 1 && !vis[j]){
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
        return ans;
    }
};

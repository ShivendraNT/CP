class Solution {
public:
    bool search(vector<vector<int>>& graph,vector<int>&color,int i){
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=abs(color[node]-1);
                }
                else if(color[it]!=abs(color[node]-1)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!search(graph,color,i)) return false;
            }
        }
        return true;
    }
};

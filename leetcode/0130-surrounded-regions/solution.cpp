class Solution {
public:
    vector<pair<int,int>> search(vector<vector<char>>& board,vector<vector<int>> & vis,int i,int j,int n,int m){
        vector<pair<int,int>> ans;
        queue<pair<int,int>> q;
        q.push({i,j});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        bool boundary=false;
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            ans.push_back({row,col});
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(board[nrow][ncol]=='O'&&!vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
                else{
                    boundary=true;
                }
            }
        }
        if(boundary) return {};
        return ans;
    }
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>> surrounded;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!vis[i][j]){
                    vector<pair<int,int>>temp=search(board,vis,i,j,n,m);
                    surrounded.insert(surrounded.end(),temp.begin(),temp.end());
                }
            }
        }
        for(auto p:surrounded){
            board[p.first][p.second]='X';
        }
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX; 
            }
        }
        
        int drow[] = {-1, 0, 1, 0}, dcol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + drow[i], nc = c + dcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] > mat[r][c] + 1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};

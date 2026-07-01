class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && safeness[nx][ny] == -1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = safeness[0][0];

        priority_queue<tuple<int,int,int>> maxHeap; // {bottleneck_value, x, y}
        maxHeap.push({safeness[0][0], 0, 0});

        while (!maxHeap.empty()) {
            auto [val, x, y] = maxHeap.top(); maxHeap.pop();

            if (val < dist[x][y]) continue;          // stale entry
            if (x == n - 1 && y == n - 1) return val;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int candidate = min(val, safeness[nx][ny]);
                    if (candidate > dist[nx][ny]) {
                        dist[nx][ny] = candidate;
                        maxHeap.push({candidate, nx, ny});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};

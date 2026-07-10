class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q_size = queries.size();
        vector<int> ans(q_size, -1);
        vector<pair<int, int>> sorted_nums(n);
        for(int i = 0; i < n; i++) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> comp(n, -1);
        int c_id = 0;
        comp[sorted_nums[0].second] = c_id;
        
        for(int i = 1; i < n; i++) {
            if(sorted_nums[i].first - sorted_nums[i-1].first > maxDiff) {
                c_id++;
            }
            comp[sorted_nums[i].second] = c_id;
        }
        vector<int> next_farthest(n);
        int r = 0;
        for(int l = 0; l < n; l++) {
            while(r < n && sorted_nums[r].first - sorted_nums[l].first <= maxDiff) {
                r++;
            }
            next_farthest[l] = r - 1; 
        }
        
        int LOG = 18; 
        vector<vector<int>> up(n, vector<int>(LOG));
        for(int i = 0; i < n; i++) {
            up[i][0] = next_farthest[i];
        }
        
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        
        vector<int> orig_to_sorted(n);
        for(int i = 0; i < n; i++) {
            orig_to_sorted[sorted_nums[i].second] = i;
        }
        
        for(int i = 0; i < q_size; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            
            if(comp[u] != comp[v]) {
                ans[i] = -1;
                continue;
            }
            
            int start = orig_to_sorted[u];
            int target = orig_to_sorted[v];
            
            if(start == target) {
                ans[i] = 0;
                continue;
            }
            
            if(start > target) swap(start, target);
            
            int steps = 0;
            int curr = start;
            
            for(int j = LOG - 1; j >= 0; j--) {
                if(up[curr][j] < target) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }
            
            ans[i] = steps + 1;
        }
        
        return ans;
    }
};

class Solution {
    int memo[1005];
    
    int dfs(vector<int>& arr, int d, int i) {
        // If we've already calculated the max jumps for this index, return it
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int n = arr.size();
        int max_jumps = 1; // You always visit at least 1 index (the starting one)
        
        // Check right jumps
        for (int j = i + 1; j <= min(i + d, n - 1); j++) {
            if (arr[j] >= arr[i]) break; // Path is blocked by a taller/equal building
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j));
        }
        
        // Check left jumps
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i]) break; // Path is blocked by a taller/equal building
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j));
        }
        
        // Save the result before returning
        return memo[i] = max_jumps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memset(memo, -1, sizeof(memo)); // Initialize memo array with -1
        
        int result = 0;
        // We can start at any index, so try all of them
        for (int i = 0; i < n; i++) {
            result = max(result, dfs(arr, d, i));
        }
        
        return result;
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n = s.size();
      
        // Prefix sum array to track count of reachable positions up to index i
        // prefixSum[i] represents the number of reachable positions in range [0, i-1]
        int prefixSum[n + 1];
        memset(prefixSum, 0, sizeof(prefixSum));
        prefixSum[1] = 1;  // Position 0 is reachable (base case)
      
        // Dynamic programming array where canReach[i] indicates if position i is reachable
        bool canReachPosition[n];
        memset(canReachPosition, 0, sizeof(canReachPosition));
        canReachPosition[0] = true;  // Starting position is always reachable
      
        // Iterate through each position in the string
        for (int i = 1; i < n; ++i) {
            // Only consider positions with '0' (valid landing positions)
            if (s[i] == '0') {
                // Calculate the valid range of positions that can jump to position i
                // leftBound: furthest position that can reach i (at most maxJump away)
                int leftBound = max(0, i - maxJump);
                // rightBound: closest position that can reach i (at least minJump away)
                int rightBound = i - minJump;
              
                // Check if there exists at least one reachable position in the valid range
                // Using prefix sum for O(1) range query
                canReachPosition[i] = (leftBound <= rightBound) && 
                                      (prefixSum[rightBound + 1] - prefixSum[leftBound] > 0);
            }
          
            // Update prefix sum with current position's reachability
            prefixSum[i + 1] = prefixSum[i] + canReachPosition[i];
        }
      
        // Return whether the last position is reachable
        return canReachPosition[n - 1];
    }
};

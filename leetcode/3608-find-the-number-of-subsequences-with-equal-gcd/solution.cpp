class Solution {
 public:
  int subsequencePairCount(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    const int maxNum = ranges::max(nums);
    vector<vector<int>> dp(maxNum + 1, vector<int>(maxNum + 1));
    dp[0][0] = 1;

    for (const int num : nums) {
      vector<vector<int>> newDp(maxNum + 1, vector<int>(maxNum + 1));
      for (int x = 0; x <= maxNum; ++x)
        for (int y = 0; y <= maxNum; ++y) {
          newDp[x][y] += dp[x][y];
          newDp[x][y] %= kMod;
          const int newX = gcd(x, num);
          newDp[newX][y] += dp[x][y];
          newDp[newX][y] %= kMod;
          const int newY = gcd(y, num);
          newDp[x][newY] += dp[x][y];
          newDp[x][newY] %= kMod;
        }
      dp = std::move(newDp);
    }

    int ans = 0;
    for (int g = 1; g <= maxNum; ++g) {
      ans += dp[g][g];
      ans %= kMod;
    }
    return ans;
  }
};

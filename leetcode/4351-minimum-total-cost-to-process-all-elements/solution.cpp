class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        vector<int> solve = nums;

        long long sum = 0;
        const long long mod = 1e9 + 7;
        for (int i : solve) {
            sum += i;
        }
        sum -= k;
        if (sum <= 0) return 0;

        long long n;
        if (sum % k == 0) {
            n = sum / k;
        } else {
            n = sum / k + 1;
        }

        long long nMod = n % mod;
        long long n1Mod = (n + 1) % mod;
        long long inv2 = (mod + 1) / 2;

        long long ans = (nMod * n1Mod) % mod;
        ans = (ans * inv2) % mod;

        return (int)ans;
    }
};

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> lcms;
        vector<int> bits;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l = l / __gcd(l, (long long)coins[i]) * coins[i];
                    if (l > 2e10) { ok = false; break; }
                }
            }
            if (ok) {
                lcms.push_back(l);
                bits.push_back(__builtin_popcount(mask));
            }
        }
        long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = 0;
            for (size_t i = 0; i < lcms.size(); i++) {
                if (bits[i] & 1) cnt += mid / lcms[i];
                else cnt -= mid / lcms[i];
            }
            if (cnt >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

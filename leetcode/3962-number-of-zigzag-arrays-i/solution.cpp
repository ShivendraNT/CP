class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int m = r - l + 1;
        
        vector<long long> dp0(m, 1), dp1(m, 1);
        vector<long long> next_dp0(m), next_dp1(m);
        vector<long long> sum0(m + 1, 0), sum1(m + 1, 0);
        
        for (int step = 0; step < n - 1; ++step) {
            for (int i = 0; i < m; ++i) {
                sum0[i + 1] = (sum0[i] + dp0[i]) % MOD;
                sum1[i + 1] = (sum1[i] + dp1[i]) % MOD;
            }
            
            long long s0_m = sum0[m];
            for (int i = 0; i < m; ++i) {
                next_dp0[i] = sum1[i]; 
                next_dp1[i] = (s0_m - sum0[i + 1] + MOD) % MOD;
            }
            
            dp0 = next_dp0;
            dp1 = next_dp1;
        }
        
        long long total = 0;
        for (int i = 0; i < m; ++i) { 
            total = (total + dp0[i] + dp1[i]) % MOD; 
        }
        
        return total;
    }
};

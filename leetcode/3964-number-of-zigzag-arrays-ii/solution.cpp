class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int k = r - l + 1;
        int size = 2 * k;
        
        // States 0..k-1: UP ending at value i (relative)
        // States k..2k-1: DOWN ending at value i (relative)
        
        auto mat_mul = [&](vector<vector<long long>>& A, vector<vector<long long>>& B) {
            int n = A.size();
            vector<vector<long long>> C(n, vector<long long>(n, 0));
            for (int i = 0; i < n; i++)
                for (int kk = 0; kk < n; kk++) {
                    if (A[i][kk] == 0) continue;
                    for (int j = 0; j < n; j++)
                        C[i][j] = (C[i][j] + A[i][kk] * B[kk][j]) % MOD;
                }
            return C;
        };
        
        auto mat_pow = [&](vector<vector<long long>> M, int p) {
            int n = M.size();
            vector<vector<long long>> result(n, vector<long long>(n, 0));
            for (int i = 0; i < n; i++) result[i][i] = 1; // identity
            while (p) {
                if (p & 1) result = mat_mul(result, M);
                M = mat_mul(M, M);
                p >>= 1;
            }
            return result;
        };
        
        // Build transition matrix
        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int v = 0; v < k; v++) {
            // UP[v]: last step was up, ended at v. Next must go DOWN (w < v)
            for (int w = 0; w < v; w++)
                T[k + w][v] = 1; // UP[v] -> DOWN[w]
            // DOWN[v]: last step was down, ended at v. Next must go UP (w > v)
            for (int w = v + 1; w < k; w++)
                T[w][k + v] = 1; // DOWN[v] -> UP[w]
        }
        
        // Initial vector after placing first 2 elements
        vector<long long> init(size, 0);
        for (int v = 0; v < k; v++) {
            // UP[v]: number of ways first element u < v
            init[v] = v;
            // DOWN[v]: number of ways first element u > v
            init[k + v] = k - 1 - v;
        }
        
        if (n == 1) return k % MOD;
        if (n == 2) return (long long)k * (k - 1) % MOD;
        
        // Apply T^(n-2) to init
        auto Tp = mat_pow(T, n - 2);
        
        long long ans = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                ans = (ans + Tp[i][j] * init[j]) % MOD;
        
        return (int)ans;
    }
};

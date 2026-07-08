class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<long long> power10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % mod;
        }

        vector<long long> pref_sum(n + 1, 0);
        vector<int> non_zero_count(n + 1, 0);
        vector<long long> suff_num(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int dig = s[i] - '0';
            pref_sum[i + 1] = (pref_sum[i] + dig) % mod;
            non_zero_count[i + 1] = non_zero_count[i] + (dig != 0 ? 1 : 0);
        }

        int current_non_zeros = 0;
        for (int i = n - 1; i >= 0; i--) {
            int dig = s[i] - '0';
            if (dig != 0) {
                suff_num[i] = (dig * power10[current_non_zeros] + suff_num[i + 1]) % mod;
                current_non_zeros++;
            } else {
                suff_num[i] = suff_num[i + 1];
            }
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];

            long long range_sum = (pref_sum[R + 1] - pref_sum[L] + mod) % mod;

            long long raw_num = (suff_num[L] - suff_num[R + 1] + mod) % mod;
            int non_zeros_after_R = non_zero_count[n] - non_zero_count[R + 1];
            
            int total_non_zeros_in_range = non_zero_count[R + 1] - non_zero_count[L];
            
            long long range_num = (suff_num[L] - suff_num[R + 1] + mod) % mod;
            
            long long inv = power(power10[non_zeros_after_R], mod - 2);
            range_num = (range_num * inv) % mod;

            long long current_ans = (range_num * range_sum) % mod;
            ans.push_back(current_ans);
        }

        return ans;
    }

private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};

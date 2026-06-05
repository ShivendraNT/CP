#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        auto count = [&](long long x) -> long long {
            if (x <= 0) return 0LL;
            std::string s = std::to_string(x);
            int n = s.length();

            // Encode: p in [-1..9], p2 in [-1..9], z bool, t bool
            // Each of p, p2 has 11 values; layout: p * 44 + p2 * 4 + z * 2 + t
            auto encode = [](int p, int p2, bool z, bool t) -> long long {
                return (long long)(p + 1) * 44
                     + (p2 + 1) * 4
                     + (z ? 1 : 0) * 2
                     + (t ? 1 : 0);
            };

            std::unordered_map<long long, std::pair<long long, long long>> dp;
            dp[encode(-1, -1, true, true)] = {1LL, 0LL};

            for (int i = 0; i < n; ++i) {
                std::unordered_map<long long, std::pair<long long, long long>> next_dp;
                int limit = s[i] - '0';

                for (auto const& [state, val] : dp) {
                    // Decode
                    long long tmp = state;
                    bool t  = tmp % 2; tmp /= 2;
                    bool z  = tmp % 2; tmp /= 2;
                    int  p2 = (int)(tmp % 11) - 1; tmp /= 11;
                    int  p  = (int)(tmp % 11) - 1;

                    for (int d = 0; d <= 9; ++d) {
                        if (t && d > limit) continue;

                        bool nz = z && (d == 0);
                        bool nt = t && (d == limit);

                        // When still leading zero, prev digits are "absent"
                        int np  = nz ? -1 : d;
                        int np2 = nz ? -1 : p;   // shift: p2 <- p, p <- d

                        long long nw = val.second;

                        // p is the digit being "finalized" as middle of (p2, p, d)
                        // Only count if all three are real (non-leading-zero) digits
                        if (!nz && p != -1 && p2 != -1) {
                            if ((p2 < p && p > d) || (p2 > p && p < d))
                                nw += val.first;
                        }

                        auto& ns = next_dp[encode(np, np2, nz, nt)];
                        ns.first  += val.first;
                        ns.second += nw;
                    }
                }
                dp = next_dp;
            }

            long long res = 0;
            for (auto const& [st, v] : dp) res += v.second;
            return res;
        };

        return count(num2) - count(num1 - 1);
    }
};

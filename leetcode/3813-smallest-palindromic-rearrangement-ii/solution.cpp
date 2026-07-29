#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    static constexpr long long LIMIT = 1000001LL;

    long long countWays(const std::vector<int>& cnt, int total) {
        long long res = 1;
        int remaining = total;

        for (int i = 0; i < 26; i++) {
            int c = cnt[i];
            
            for (int j = 1; j <= c; j++) {
                res = res * (remaining - c + j) / j;

                if (res > LIMIT) {
                    return LIMIT;
                }
            }

            remaining -= c;
        }

        return std::min(res, LIMIT);
    }

public:
    std::string smallestPalindrome(std::string s, int k) {
        std::vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        std::vector<int> half(26, 0);
        int len = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];

            if ((freq[i] & 1) == 1) {
                mid = (char)('a' + i);
            }
        }

        // If total unique permutations possible are less than k, return empty string
        if (countWays(half, len) < k) {
            return "";
        }

        std::string left = "";

        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) {
                    continue;
                }

                half[ch]--;

                long long ways = countWays(half, len - pos - 1);

                if (ways >= k) {
                    left.push_back((char)('a' + ch));
                    break;
                }

                k -= ways;
                half[ch]++; // Backtrack
            }
        }

        // Construct full palindromic string
        std::string ans = left;

        if (mid != 0) {
            ans.push_back(mid);
        }

        std::string right = left;
        std::reverse(right.begin(), right.end());
        ans += right;

        return ans;
    }
};

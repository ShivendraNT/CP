#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::unordered_map<long long, int> count;
        long long max_num = 0;
        
        // Count frequencies and find the maximum number to avoid overflow
        for (int num : nums) {
            count[num]++;
            max_num = std::max(max_num, (long long)num);
        }
        
        // Handle the edge case of 1s
        int ans = 0;
        if (count.count(1)) {
            ans = count[1] % 2 == 0 ? count[1] - 1 : count[1];
        } else {
            ans = 1; // Any single element can form a valid sequence of length 1
        }
        
        // Check sequences for numbers > 1
        for (int num : nums) {
            if (num == 1) continue;
            
            int current_length = 0;
            long long x = num;
            
            // Chain upwards as long as we have at least 2 copies of the current base
            while (x <= max_num && count.count(x) && count[x] >= 2) {
                current_length += 2;
                x = x * x; // Square the base
            }
            
            // Check if the final squared element can act as the single peak in the center
            if (count.count(x) && count[x] >= 1) {
                current_length += 1;
            } else {
                current_length -= 1; // Backtrack peak if it doesn't exist
            }
            
            ans = std::max(ans, current_length);
        }
        
        return ans;
    }
};


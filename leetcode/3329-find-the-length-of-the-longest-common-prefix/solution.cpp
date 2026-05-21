#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> prefixes;
        
        // Step 1: Insert all mathematical prefixes of arr1 into the hash set
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; // Chops off the last digit
            }
        }
        
        int maxLength = 0;
        
        // Step 2: Check all prefixes of arr2 against the hash set
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {
                    // Calculate the number of digits in the matching prefix
                    int currentLength = std::to_string(val).length();
                    maxLength = std::max(maxLength, currentLength);
                    
                    // Optimization: Since we are checking from the longest prefix 
                    // down to the shortest, the first match for this specific 
                    // number will always yield its maximum possible prefix length.
                    break;
                }
                val /= 10;
            }
        }
        
        return maxLength;
    }
};

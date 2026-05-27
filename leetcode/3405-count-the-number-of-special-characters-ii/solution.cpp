class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<int> last_lower(26, -1);
        std::vector<int> first_upper(26, -1);
        std::vector<bool> invalid(26, false);
        
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            
            if (std::islower(ch)) {
                int idx = ch - 'a';
                last_lower[idx] = i;
                if (first_upper[idx] != -1) {
                    invalid[idx] = true;
                }
            } else {
                int idx = ch - 'A';
                // Only record the FIRST occurrence of the uppercase letter
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i;
                }
            }
        }
        
        int special_count = 0;
        // Verify conditions for all 26 English alphabets
        for (int i = 0; i < 26; ++i) {
            if (!invalid[i] && last_lower[i] != -1 && first_upper[i] != -1) {
                if (last_lower[i] < first_upper[i]) {
                    special_count++;
                }
            }
        }
        
        return special_count;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, ans = 0, r = 0;
        unordered_map<char, int> mpp; 
        
        while (r < s.size()) {
            mpp[s[r]]++;
            
            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                ans += (s.size() - r);
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};

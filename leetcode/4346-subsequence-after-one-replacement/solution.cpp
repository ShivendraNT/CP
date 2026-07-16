class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m) return false;

        vector<int> left_pos(n, m); 
        int t_ptr = 0;
        for (int i = 0; i < n; i++) {
            while (t_ptr < m && t[t_ptr] != s[i]) {
                t_ptr++;
            }
            if (t_ptr < m) {
                left_pos[i] = t_ptr;
                t_ptr++; 
            } else {
                break; 
            }
        }

        if (left_pos[n - 1] < m) return true;

        vector<int> right_pos(n, -1);
        t_ptr = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (t_ptr >= 0 && t[t_ptr] != s[i]) {
                t_ptr--;
            }
            if (t_ptr >= 0) {
                right_pos[i] = t_ptr;
                t_ptr--;
            } else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            int left_bound = (i > 0) ? left_pos[i - 1] : -1;
            
            int right_bound = (i < n - 1) ? right_pos[i + 1] : m;

            if (left_bound < right_bound - 1) {
                return true;
            }
        }

        return false;
    }
};

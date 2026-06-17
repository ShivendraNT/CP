class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> lengths;
        long long current_size = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                current_size++;
            } else if (c == '#') {
                current_size *= 2;
            } else if (c == '%') {
            } else { 
                if (current_size > 0) current_size--;
            }
            lengths.push_back(current_size);
        }

        if (k >= current_size || k < 0) return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            long long prev_size = (i == 0) ? 0 : lengths[i - 1];

            if (c >= 'a' && c <= 'z') {
                if (k == current_size - 1) {
                    return c;
                }
                current_size--;
            } 
            else if (c == '#') {
                current_size /= 2;
                k %= current_size;
            } 
            else if (c == '%') {
                k = current_size - 1 - k;
            } 
            else {
                current_size++; 
            }
        }

        return '.';
    }
};

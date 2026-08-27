class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> total_count(26, 0);
        for (char ch : s) {
            total_count[ch - 'a']++;
        }
        for (int i = n - 1; i >= 0; --i) {
            vector<int> count = total_count;
            bool possible = true;

            for (int j = 0; j < i; ++j) {
                if (--count[target[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (count[c] > 0) {
                    count[c]--;

                    string result = target.substr(0, i);
                    result.push_back(static_cast<char>('a' + c));

                    for (int rem = 0; rem < 26; ++rem) {
                        result.append(count[rem], static_cast<char>('a' + rem));
                    }

                    return result;
                }
            }
        }

        return "";
    }
};

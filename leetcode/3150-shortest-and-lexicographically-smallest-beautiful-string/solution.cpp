class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int num1 = 0;
        string ans = "";

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                num1++;
            }
            while (num1 == k) {
                string sub = s.substr(i, j - i + 1);
                
                if (ans == "" || sub.length() < ans.length() || (sub.length() == ans.length() && sub < ans)) {
                    ans = sub;
                }

                if (s[i] == '1') {
                    num1--;
                }
                i++;
            }
        }

        return ans;
    }
};

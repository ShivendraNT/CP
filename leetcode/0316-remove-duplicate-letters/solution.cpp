class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int> last(26, -1);
        for(int i = 0; i < n; i++) last[s[i]-'a'] = i;

        vector<bool> remaining(26, false);
        int cntRemaining = 0;
        for(int c = 0; c < 26; c++)
            if(last[c] != -1){ remaining[c] = true; cntRemaining++; }

        string ans = "";
        int start = 0;

        while(cntRemaining > 0){
            int limit = n;
            for(int c = 0; c < 26; c++)
                if(remaining[c]) limit = min(limit, last[c]);

            int bestC = 26, bestIdx = -1;
            for(int i = start; i <= limit; i++){
                int c = s[i]-'a';
                if(remaining[c] && c < bestC){ bestC = c; bestIdx = i; }
            }

            ans += (char)('a' + bestC);
            remaining[bestC] = false;
            cntRemaining--;

            start = bestIdx + 1;
        }
        return ans;
    }
};

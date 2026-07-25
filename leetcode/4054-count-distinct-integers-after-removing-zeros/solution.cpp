class Solution {
public:
    string s;
    long long memo[20][2];
    bool vis[20][2];

    long long solve(int pos, bool tight){
        if(pos == (int)s.size()) return 1;
        if(vis[pos][tight]) return memo[pos][tight];
        vis[pos][tight] = true;

        int limit = tight ? (s[pos] - '0') : 9;
        long long cnt = 0;
        for(int d = 1; d <= limit; d++)
            cnt += solve(pos + 1, tight && (d == limit));

        return memo[pos][tight] = cnt;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        memset(vis, false, sizeof(vis));

        long long ans = solve(0, true);      
        long long p = 9;
        for(int d = 1; d < (int)s.size(); d++){
            ans += p;
            p *= 9;
        }
        return ans;
    }
};

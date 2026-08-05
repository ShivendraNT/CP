#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(int u, vector<vector<int>>& adj, vector<ll>& a, vector<ll>& hidden, ll& base_score, int& leaf_count) {
    if (adj[u].empty()) {
        leaf_count++;
        return a[u];
    }
    vector<ll> child_chains;
    for (int v : adj[u]) {
        child_chains.push_back(dfs(v, adj, a, hidden, base_score, leaf_count));
    }
    sort(child_chains.begin(), child_chains.end());
    ll min_chain=child_chains[0];
    for (size_t i = 1; i < child_chains.size(); i++) {
        base_score += child_chains[i];
    }
    hidden.push_back(min(a[u], min_chain));
    return max(a[u], min_chain);
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    vector<ll> hidden;
    ll base_score = 0;
    int leaf_count = 0;

    ll root_chain=dfs(1, adj, a, hidden, base_score, leaf_count);
    base_score += root_chain;
    sort(hidden.rbegin(), hidden.rend());
    vector<ll> ans(n + 1, -1);

    ll current_score = base_score;
    ans[leaf_count] = current_score;
    for (size_t i = 0; i < hidden.size(); i++) {
        current_score += hidden[i];
        ans[leaf_count + i + 1] = current_score;
    }
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << (k == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
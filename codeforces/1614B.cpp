#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    
    vector<pair<ll, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    
    sort(p.rbegin(), p.rend());
    
    vector<ll> ans(n + 1, 0);
    ll total_time = 0;
    ll pos = 1;
    
    for (int i = 0; i < n; i++) {
        ll val = (i % 2 == 0) ? pos : -pos;
        
        ans[p[i].second] = val;
        total_time += 2 * p[i].first * pos;
        
        if (i % 2 == 1) {
            pos++;
        }
    }
    
    cout << total_time << '\n';
    
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> pref(n + 1, 0); 
    
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    
    ll total_sum = pref[n];
    
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll current_sum = total_sum - (pref[r] - pref[l - 1]) + (r - l + 1) * k;
        
        if (current_sum & 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
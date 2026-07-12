#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll pw(ll b, ll e) { ll r = 1; b %= MOD; while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; } return r; }

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    int i = 0, m = 0;
    while (i < n && a[i] == -1) { m++; i++; }
    int P = n - m;

    vector<ll> val; vector<int> cnt;           
    for (int j = i; j < n; j++) {
        if (!val.empty() && val.back() == a[j]) cnt.back()++;
        else { val.push_back(a[j]); cnt.push_back(1); }
    }
    int G = val.size();

    ll D = 0;                                  
    for (int g = 0; g + 1 < G; g++) if (val[g + 1] - val[g] == 1) D++;

    ll base = pw(2, P - G);                     
    ll E = (m == 0 ? 1 : pw(2, m - 1));        
    ll O = (m == 0 ? 0 : pw(2, m - 1));        

    cout << base % MOD * ((E + O % MOD * D) % MOD) % MOD << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
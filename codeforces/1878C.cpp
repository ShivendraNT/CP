#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k, x; 
    cin >> n >> k >> x;

    ll min_sum = k * (k + 1) / 2;

    ll max_sum = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

    if (x >= min_sum && x <= max_sum) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
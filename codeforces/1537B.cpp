#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, i, j;
    cin >> n >> m >> i >> j;
    
    // Always throw at opposite corners: (1, 1) and (n, m)
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    if (n % 2 != 0 || n < 4) {
        cout << -1 << '\n';
        return;
    }

    ll maxbus = n / 4;

    ll minbus = n / 6;
    if (n % 6 != 0) {
        minbus++;
    }

    cout << minbus << " " << maxbus << '\n';
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
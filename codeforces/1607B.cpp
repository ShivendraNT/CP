#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x0, n;
    cin >> x0 >> n;
    
    ll rem = n % 4;
    ll change = 0;
    
    if (rem == 1) {
        change = -n;
    } else if (rem == 2) {
        change = 1;
    } else if (rem == 3) {
        change = n + 1;
    }
    
    if (x0 % 2 != 0) {
        cout << x0 - change << '\n';
    } else {
        cout << x0 + change << '\n';
    }
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
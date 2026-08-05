#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int mindist = k;
    int even_count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0) {
            even_count++;
        }

        int rem = x % k;
        if (rem == 0) {
            mindist = 0;
        } else {
            mindist = min(mindist, k - rem);
        }
    }

    if (k == 4) {
        int cost_for_two_evens = max(0, 2 - even_count);
        mindist = min(mindist, cost_for_two_evens);
    }

    cout << mindist << "\n";
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
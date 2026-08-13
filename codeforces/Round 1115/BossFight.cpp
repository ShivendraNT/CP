#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    map<int, int> freq;
    ll total_sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        total_sum += x;
    }

    int max_freq = 0;
    int max_val = 0;

    for (auto p : freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
            max_val = p.first;
        }
    }

    int count_rest = n - max_freq;
    ll sum_rest = 0;
    for (auto p : freq) {
        if (p.first != max_val) {
            sum_rest += 1LL * p.first * p.second;
        }
    }

    if (max_freq <= count_rest + 1) {
        cout << total_sum << "\n";
    } else {
        ll ans = sum_rest + 1LL * (count_rest + 2) * max_val;
        cout << ans << "\n";
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
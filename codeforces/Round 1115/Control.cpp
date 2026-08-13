#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b, cnt;
    for (int i = 0; i < n; i++) {
        if (!b.empty() && b.back() == a[i]) cnt.back()++;
        else {
            b.push_back(a[i]);
            cnt.push_back(1);
        }
    }

    int m = b.size();

    // +2 : two neighbouring runs both have >= 2 elements
    for (int i = 0; i + 1 < m; i++) {
        if (cnt[i] >= 2 && cnt[i + 1] >= 2) {
            cout << m + 2 << "\n";
            return;
        }
    }

    // +1 : one run with >= 2 elements that can be fixed by one swap
    for (int i = 0; i < m; i++) {
        if (cnt[i] < 2) continue;
        // swap the duplicate with the run on its right
        if (i + 1 < m && (i + 2 >= m || b[i + 2] != b[i])) {
            cout << m + 1 << "\n";
            return;
        }
        // swap the duplicate with the run on its left
        if (i - 1 >= 0 && (i - 2 < 0 || b[i - 2] != b[i])) {
            cout << m + 1 << "\n";
            return;
        }
    }

    cout << m << "\n";
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
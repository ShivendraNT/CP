#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxdiff = nums[n - 1] - nums[0];

    for (int i = 0; i < n; i++) {

        if (i < n - 1) {
            maxdiff = max(maxdiff, nums[i] - nums[i + 1]);
        }
        if (i < n - 1) {
            maxdiff = max(maxdiff, nums[n - 1] - nums[i]);
        }
        if (i > 0) {
            maxdiff = max(maxdiff, nums[i] - nums[0]);
        }
    }

    cout << maxdiff << '\n';
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
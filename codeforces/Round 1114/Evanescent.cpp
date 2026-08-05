#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int base_len = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i+1]) {
            base_len++;
        }
    }
    int max_reduction = 0;
    for (int i = 1; i < n - 1; i++) {
        int reduction = 0;
        if (s[i-1] == s[i+1] && s[i] != s[i-1]) {
            reduction = 2;
        } else if (s[i] != s[i-1] && s[i] != s[i+1]) {
            reduction = 1;
        }
        max_reduction = max(max_reduction, reduction);
    }
    cout << base_len - max_reduction << "\n";
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
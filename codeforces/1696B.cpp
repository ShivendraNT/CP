#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int segments = 0;
    bool in_segment = false;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (x != 0) {
            if (!in_segment) {
                segments++;
                in_segment = true;
            }
        } else {
            in_segment = false;
        }
    }
    
    // Ab exact logic check lagao
    if (segments == 0) {
        cout << 0 << '\n';
    } else if (segments == 1) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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
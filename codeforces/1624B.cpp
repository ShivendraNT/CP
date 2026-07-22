#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    // a is changed
    ll anew = 2 * b - c;
    if (anew > 0 && anew % a == 0) {
        cout << "YES" << '\n';
        return;
    }
    
    // b is changed
    if ((a + c) % 2 == 0) {
        ll bnew = (a + c) / 2;
        if (bnew > 0 && bnew % b == 0) {
            cout << "YES" << '\n';
            return;
        }
    }
    
    // c is changed
    ll cnew = 2 * b - a;
    if (cnew > 0 && cnew % c == 0) {
        cout << "YES" << '\n';
        return;
    }
    cout<<"NO"<<'\n';
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
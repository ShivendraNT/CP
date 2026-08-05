#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll total_sum = 0;
    multiset<ll> ms;
    
    for(int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        total_sum += val;
        ms.insert(val);
    }
    
    if(total_sum <= 0) {
        cout << -1 << "\n";
        return;
    }
    
    ll curr_sum = 0;
    vector<ll> a;
    
    for(int i = 0; i < n; i++) {
        auto it = ms.lower_bound(-curr_sum + 1);
        
        ll x = *it;
        ms.erase(it);
        curr_sum += x;
        a.push_back(curr_sum);
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
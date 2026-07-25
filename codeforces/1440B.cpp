#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    if (!(cin >> n >> k)) return;
    ll sz = n * k;
    vector<ll> a(sz);
    for(int i=0;i<sz;i++){
        cin>>a[i];
    }
    ll step=n-(n+1)/2 +1;
    ll sum=0;
    ll idx=sz-step;
    for(int i=0;i<k;i++){
        if (idx >= 0 && idx < sz) {
            sum += a[idx];
        }
        idx-=step;
    }
    cout<<sum<<"\n";
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
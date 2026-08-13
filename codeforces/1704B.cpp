#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    ll maxelem=a[0];
    ll minelem=a[0];
    for(int i=1;i<n;i++){
        maxelem=max(maxelem,a[i]);
        minelem=min(minelem,a[i]);
        if(maxelem-minelem>2*x){
            ans++;
            maxelem=a[i];
            minelem=a[i];
        }
    }
    cout<<ans<<'\n';
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
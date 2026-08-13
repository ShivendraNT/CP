#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll L=0;
    for(int i=0;i<n;i++){
        if(a[i]<=q){
            L++;
        }
        else{
            if(L>=k) ans+=(L-k+1)*(L-k+2)/2;
            L=0;
        }
    }
    if(L>=k) ans+=(L-k+1)*(L-k+2)/2;
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
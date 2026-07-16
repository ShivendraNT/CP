#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    sort(a.begin(),a.end());
    ll ans=sum-c*n;
    ll half=n/2;
    for(int i=0;i<half;i++){
        ll g=c-a[i];
        if(g<=0)break;
        ans+=g;
    }
    cout<<ans<<"\n";
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
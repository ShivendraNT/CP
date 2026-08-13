#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
     int n1,n2,n3;
     cin>>n1>>n2>>n3;
     int maxelem=max({n1,n2,n3});
     int minelem=min({n1,n2,n3});
     int midelem=n1+n2+n3-maxelem-minelem;
     int ans=min(maxelem-minelem,midelem);
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
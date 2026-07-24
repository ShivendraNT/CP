#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a,b;
    cin>>a>>b;
    ll d=llabs(a-b);
    if(d==0){
        cout<<"0 0"<<'\n';
        return;
    }
    ll r=a%d;
    cout<<d<<" "<<min(d-r,r)<<'\n';
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
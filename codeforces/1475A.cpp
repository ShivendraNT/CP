#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    if((n&(n-1))==0){
        cout<<"NO"<<'\n';
    }
    else{
        cout<<"YES"<<'\n';
    }
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
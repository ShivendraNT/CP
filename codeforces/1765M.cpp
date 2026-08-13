#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    ll p=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            p=i;
            break;
        }
    }
    if(p==0){
        cout<<1<<" "<<n-1<<'\n';
    }
    else{
        cout<<n/p<<" "<<n-n/p<<'\n';
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
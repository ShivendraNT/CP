#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll h,w;
    cin>>w>>h;
    ll maxarea=INT_MIN;
    for(int i=0;i<4;i++){
        ll k;
        cin>>k;
        ll first,last;
        cin>>first;
        for(int i=1;i<k-1;i++){
            ll x;
            cin>>x;
        }
        cin>>last;
        ll base=last-first;
        if(i<=1){
            maxarea=max(maxarea,base*h);
        }
        else{
            maxarea=max(maxarea,base*w);
        }
    }
    cout<<maxarea<<'\n';
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
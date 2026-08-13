#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a,b;
    cin>>a>>b;
    ll ans=INT_MAX;
    for(int inc=0;inc<36;inc++){
        ll new_b=b+inc;
        if(new_b==1){
            continue;
        }
        ll op=inc;
        ll copya=a;
        while(copya>0){
            copya/=new_b;
            op++;
        }
        ans=min(ans,op);
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
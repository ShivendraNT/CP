#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k,b,s;
    cin>>n>>k>>b>>s;
    ll minsum=b*k;
    ll maxsum=b*k+(k-1)*n;
    if(s<minsum || s>maxsum){
        cout<<-1<<'\n';
        return;
    }
    ll minus=min(s,(b+1)*k - 1);
    cout<<minus<<" ";
    s-=minus;
    for(int i=1;i<n;i++){
        minus=min(s,k-1);
        s-=minus;
        cout<<minus<<" ";
    }
    cout<<'\n';
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
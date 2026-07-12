#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a,b,n;
    cin>>a>>b>>n;
    ll sum=b-1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        sum+=min(a-1,x);
    }
    cout<<sum+1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,x;
    cin>>n>>x;
    ll max=0;
    ll min=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        max+=(num + x - 1) / x;
        min+=num;
    }
    min=(min + x - 1) / x;
    cout<<min<<" "<<max<<'\n';
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
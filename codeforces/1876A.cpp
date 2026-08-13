#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<pair<ll,ll>> residents(n);
    for(int i=0;i<n;i++){
        residents[i]={b[i],a[i]};
    }
    sort(residents.begin(),residents.end());
    ll total_cost=p;
    ll needed=n-1;
    for(int i=0;i<n&&needed>0 ;i++){
        ll cost=residents[i].first;
        ll capacity=residents[i].second;
        if(cost>=p){
            break;
        }
        ll take=min(needed,capacity);
        total_cost+=take*cost;
        needed-=take;
    }
    if(needed>0){
        total_cost+=needed*p;
    }
    cout<<total_cost<<'\n';
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool customComp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.first != b.first) {
        return a.first > b.first; 
    }
    return a.second < b.second;   
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> pairs(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll rem = x % k;
        if (rem == 0) rem = k; 
        
        pairs[i] = {rem, i + 1};
    }
    sort(pairs.begin(),pairs.end(),customComp);
    for(int i=0;i<n;i++){
        cout<<pairs[i].second<<" ";
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
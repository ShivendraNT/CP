#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,m;
    cin>>n>>m;
    
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    ll minsteps = m; 
    
    vector<ll> pool; 

    for(int i=n-1; i>=0; i--){
        
        for(int j=0; j<m; j++){
            pool.push_back(grid[i][j]);
        }
        
        sort(pool.rbegin(), pool.rend());
        
        if(pool.size() > m){
            pool.resize(m);
        }
        
        ll totalrem = 0;
        int pt = 0;
        
        while(pt < pool.size() && totalrem < a[i]){
            totalrem += pool[pt];
            pt++;
        }
        
        if(totalrem >= a[i]){
            minsteps = min(minsteps, (ll)pt);
        }
    }
    
    cout<<minsteps<<"\n";
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
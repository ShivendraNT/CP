#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    ll numone=0;
    ll numzero=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            numone++;
        }
        if(x==0){
            numzero++;
        }
    }
    numzero=pow(2,numzero);
    cout<<numone*numzero<<'\n';
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
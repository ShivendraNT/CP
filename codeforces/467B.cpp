#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> players(m);
    for(int i=0;i<m;i++){
        cin>>players[i];
    }
    int fed;
    cin>>fed;
    int friends=0;
    for(int i=0;i<m;i++){
        int pl=players[i];
        int xori=pl^fed;
        int cntdiff=0;
        while(xori){
            xori&=xori-1;
            cntdiff++;
        }
        if(cntdiff<=k){
            friends++;
        }
    }
    cout<<friends<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
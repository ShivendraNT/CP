#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int l[5001],r[5001],u[5001],v[5001];

bool possible(int m){
    int pos=1;
    for(int i=1;i<=n;i++){
        if(pos>m) break;
        int right=m-pos+1;
        bool leftpos=(pos<l[i] || pos >r[i]);
        bool rightpos=(right<u[i] || right>v[i]);
        if(leftpos&&rightpos) pos++;
    }
    return pos==m+1;
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i]>>u[i]>>v[i];
    }
    int ans=0;
    for(int m=1;m<=n;m++){
        if(possible(m)) ans=m;
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
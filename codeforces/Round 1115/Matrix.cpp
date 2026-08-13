#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> a(x),b(y);
    vector<bool> apres(n+m+1,false),bpres(n+m+1,false);
    for(int i=0;i<x;i++){
        cin>>a[i];
        apres[a[i]]=true;
    }
    for(int i=0;i<y;i++){
        cin>>b[i];
        bpres[b[i]]=true;
    }
    int p=0,q=0,total=0;
    long long ans=0;
    for(int i=n+m;i>=1;i--){
        if(!apres[i]&&!bpres[i]){
            continue;
        }
        if(total==n+m-1){
            break;
        }
        if(apres[i] && bpres[i]){
            ans+=i;
            total++;
        }
        else if(apres[i]){
            if(p==n) continue;
            p++;
            ans+=i;
            total++;
        }
        else{
            if(q==m) continue;
            q++;
            ans+=i;
            total++;
        }
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
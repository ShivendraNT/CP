#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n+1, vector<char>(n+1,0));
    for(int k=0;k<m;k++){
        int o,i,j;cin>>o>>i>>j;
        mat[i][j]=o;mat[j][i]=o;
    }
    vector<int> c1(n+1,0);
    vector<char> alive(n+1,1);
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++) if(mat[i][j]==1) cnt++;
        c1[i]=cnt;
    }
    vector<int> ans(n+1,0);
    int cur=n,mag=n;           
    bool ok=true;
    for(int step=0;step<n;step++){
        int pick=-1,sign=0;
        for(int i=1;i<=n;i++){
            if(!alive[i])continue;
            if(c1[i]==cur){pick=i;sign=1;break;}  
            if(c1[i]==0){pick=i;sign=-1;break;}    
        }
        if(pick==-1){ok=false;break;}
        ans[pick]=sign*mag;
        alive[pick]=0;cur--;mag--;
        for(int j=1;j<=n;j++)
            if(alive[j] && mat[pick][j]==1) c1[j]--;
    }
    if(!ok){cout<<"NO"<<"\n";return;}
    cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

void solve() {
     int n;
     string s;
     cin>>n>>s;
     ll ans=1;
     for(int par=0;par<2;par++){
        int ok=0;
        for(int start=0;start<2;start++){
            bool good =true;
            int want=start;
            for(int i=par;i<n;i+=2){
                if(s[i]!='?' && s[i]-'0' != want){
                    good = false;
                    break;
                }
                want=1-want;
            }
            if(good==true){
                ok++;
            }
        }
        ans = ans * ok % MOD;
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
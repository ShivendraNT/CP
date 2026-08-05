#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k > n-2){ cout<<-1<<'\n'; return; } 

    int b=n-k, z=(b+1)/2, o=b/2, c0=(n+1)/2, c1=n/2;
    string ans(c0-z+1,'0');
    ans+=string(c1-o+1,'1');
    char curr='0';
    for(int i=0;i<b-2;i++){ ans+=curr; curr=(curr=='0')?'1':'0'; }
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
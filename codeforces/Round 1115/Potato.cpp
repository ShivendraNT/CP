#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int blue=0;
    int red=0;
    int m=2*n;
    for(int i=0;i<m;i++){
        if(s[i]!='1') continue;
        int next = (i+1) % m;
        int blow=(s[next]=='0')?next:i;
        if(blow%2==0){
            blue++;
        }
        else{
            red++;
        }
    }
    cout<<red<<" "<<blue<<'\n';
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
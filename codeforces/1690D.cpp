#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int numblack=0;
    for(int i=0;i<k;i++){
        if(s[i]=='B') numblack++;
    }
    int minreq=k-numblack;
    for(int i=1;i<=n-k;i++){
        if(s[i-1]=='B') numblack--;
        if(s[i+k-1]=='B') numblack++;
        minreq=min(minreq,k-numblack);
    }
    cout<<minreq<<'\n';
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
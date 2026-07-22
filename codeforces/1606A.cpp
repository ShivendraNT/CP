#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]==s[n-1]){
        cout<<s<<'\n';
    }
    else{
        s[0]=s[n-1];
        cout<<s<<'\n';
    }
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
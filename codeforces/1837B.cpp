#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxlen=0;
    int len=1;
    char curr=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==curr){
            len++;
        }
        else{
            curr=s[i];
            maxlen=max(maxlen,len);
            len=1;
        }
    }
    maxlen=max(maxlen,len);
    cout<<maxlen+1<<'\n';
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
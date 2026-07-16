#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    string arr;
    cin>>arr;
    if(k>n/2){
        cout<<-1<<'\n';
        return;
    }
    int ans=0;
    for(int i=0;i<k;i++){
        if(arr[i]=='L'){
            ans++;
        }
    }
    for(int i=0;i<k;i++){
        if(arr[n-1-i]=='R'){
            ans++;
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
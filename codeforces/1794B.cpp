#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int prev;
    cin>>prev;
    if(prev==1){
        prev++;
    }
    cout<<prev<<" ";
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            x++;
        }
        if(x%prev==0){
            x++;
        }
        cout<<x<<" ";
        prev=x;
    }
    cout<<'\n';
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
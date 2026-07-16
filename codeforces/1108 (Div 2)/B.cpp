#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    if(n==2){
        cout<<-1<<"\n";
        return;
    }
    cout<<1<<" ";
    cout<<2<<" ";
    ll prev=3;
    cout<<prev<<" ";
    for(int i=3;i<n;i++){
        prev*=2;
        cout<<prev<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
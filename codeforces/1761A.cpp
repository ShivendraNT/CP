#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b<n-1){
        cout<<"YES"<<endl;
        return;
    }
    if(a+b==n-1){
        cout<<"NO"<<endl;
        return;
    }
    if(a==b && a==n){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(n%k!=0){
        cout<<1<<endl;
        cout<<n<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<1<<endl;
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
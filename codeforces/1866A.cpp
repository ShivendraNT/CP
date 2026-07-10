#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int diff=INT_MAX;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        diff=min(diff,abs(x));
    }
    cout<<diff<<endl;
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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    bool sorted=true;
    int prev;
    cin>>prev;
    int maxdif=INT_MAX;
    for(int i=1;i<n;i++){
        int n;
        cin>>n;
        if(n<prev){
            sorted=false;
            continue;
        }
        maxdif=min(maxdif,n-prev);
        prev=n;
    }
    if(!sorted){
        cout<<0<<endl;
        return;
    }
    int ans=maxdif/2+1;
    cout<<ans<<endl;
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
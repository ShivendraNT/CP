#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int len=0;
    int currlen=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            len=max(len,currlen);
            currlen=0;
        }
        else{
            currlen++;
        }
    }
    len=max(len,currlen);
    cout<<len<<endl;
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
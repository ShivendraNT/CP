#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    if(n%2==0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        if(k%2==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
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
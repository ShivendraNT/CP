#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d<b){
        cout<<-1<<endl;
        return;
    }
    int steps=d-b;
    a=a+steps;
    if(c>a){
        cout<<-1<<endl;
        return;
    }
    steps+=a-c;
    cout<<steps<<endl;
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
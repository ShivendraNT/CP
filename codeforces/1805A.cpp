#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    for(int i=1;i<n;i++){
        int el;
        cin>>el;
        x^=el;
    }
    if(n%2==0 && x!=0){
        cout<<-1<<endl;
        return;
    }
    cout<<x<<endl;
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
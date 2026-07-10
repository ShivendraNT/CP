#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    if(sum%2==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
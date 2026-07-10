#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    bool flag=false;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==k) flag=true;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;  
    for (int i = 0; i < t; i++) solve();
    return 0;
}
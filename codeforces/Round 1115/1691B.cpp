#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> ans(n);
    int i=n-1;
    while(i>=0){
        int j=i;
        while(j>=0 && a[j]==a[i]){
            j--;
        }
        if(i == j+1){               
            cout<<-1<<'\n';
            return;
        }
        for(int t=j+1; t<i; t++){
            ans[t]=t+1;             
        }
        ans[j+1+ (i-j-1)]=j+1;
        i=j;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
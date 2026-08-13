#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    ll global_min=LLONG_MAX;
    ll second_min=LLONG_MAX;
    ll sum=0;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<ll> a(m);
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        sort(a.begin(),a.end());
        ll min1=a[0];
        ll min2=a[1];
        global_min=min(global_min,min1);
        second_min=min(second_min,min2);
        sum+=min2;
    }
    if(n==1){
        cout<<global_min<<"\n";
    }
    else{
        cout<<sum+global_min-second_min<<"\n";
    }
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
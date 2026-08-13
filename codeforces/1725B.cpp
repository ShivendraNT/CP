#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; ll D;
    cin>>n>>D;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int left=0;
    int right=n-1;
    int ans=0;
    while(right>=left){
        ll need = D / a[right] + 1;
        if(right - left + 1 >= need){    // itne available hain?
            ans++;
            left += (need - 1);          // fillers use kiye (leader ke alawa)
            right--;                     // leader use hua
        } else break;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
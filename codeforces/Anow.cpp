#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int oddmin=INT_MAX;
    int evenmax=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i%2==1){
            evenmax=max(evenmax,x);
        }
        else{
            oddmin=min(oddmin,x);
        }
    }
    if(n%2!=0){
        cout<<"NO"<<'\n';
        return;
    }
    if(oddmin-evenmax>=2){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
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
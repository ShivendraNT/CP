#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int moves=0;
    while(n%3==0){
        if(n%6==0){
            moves++;
            n/=6;
        }
        else{
            n*=2;
            n/=6;
            moves+=2;
        }
    }
    if(n==1){
        cout<<moves<<'\n';
    }
    else{
        cout<<-1<<'\n';
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
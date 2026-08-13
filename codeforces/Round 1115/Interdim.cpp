#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x,y;
    cin>>x>>y;
    ll n=0;
    while((n+1)*(n+2)/2<=x+y){
        n++;
    }
    ll sum=n*(n+1)/2;
    ll d=x+y-sum;
    ll p=x-d/2;
    p = max(p, sum - y);
    p = max(p, 0LL);
    p = min(p, x);
    p = min(p, sum);
    string s(n,'Y');
    ll rem=p;
    for(int w=n;w>=1;w--){
        if(w<=rem){
            s[n-w]='X';
            rem-=w;
        }
    }
    cout<<s<<'\n';
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
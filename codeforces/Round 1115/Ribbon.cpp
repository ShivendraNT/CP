#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD=998244353;
ll MAXN=1000006;
vector<ll> fact(MAXN);

ll power(ll a,ll b,ll m){
    ll res=1;
    a%=m;
    while(b>0){
        if(b&1){
            res=res*a%m;
        }
        a=a*a%m;
        b>>=1;
    }
    return res;
}

ll inv(ll a){
    return power(a,MOD-2,MOD);
}
ll nCr(ll n, ll r){
    if(r < 0 || r > n) return 0;
    return fact[n] * inv(fact[r]) % MOD * inv(fact[n-r]) % MOD;
}

void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    ll Z=0, O=0;          // total zeros, total ones
    ll kz=0, ko=0;
    int i=0;
    while(i<n){
        int j=i;
        while(j<n && s[i]==s[j]){
            j++;
        }
        int block=j-i;
        if(s[i]=='0'){
            Z += block;
            kz++;
        }
        else{
            O += block;
            ko++;
        }
        i=j;
    }
    ll a = (kz==0) ? 1 : nCr(Z-1, kz-1);
    ll b = (ko==0) ? 1 : nCr(O-1, ko-1);
    cout << a * b % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    fact[0]=1;
    for(int i=1;i<MAXN;i++){
        fact[i]=fact[i-1]*i%MOD;
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
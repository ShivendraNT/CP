#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,r,b;
    cin>>n>>r>>b;
    b+=1;
    int minreq=r/b;
    int rem=r%b;
    int i=0;
    b--;
    string s="";
    while(i<n){
        for(int j=0;j<minreq;j++){
            s+='R';
        }
        i+=minreq;
        if(rem>0){
            i++;
            rem--;
            s+='R';
        }
        if(b>0){
            i++;
            b--;
            s+='B';
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    bool zero=0;
    bool five=0;
    int removed=0;
    if(n%25==0){
        cout<<0<<'\n';
        return;
    }
    while(n>0){
        int dig=n%10;
        n/=10;
        removed++;
        if(dig==0){
            if(zero){
                break;
            }
            zero=true;
        }
        else if(dig==5){
            if(zero){
                break;
            }
            five=true;
        }
        else if(dig==2 && five){
            break;
        }
        else if(dig==7 && five){
            break;
        }
    }
    cout<<removed-2<<'\n';
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int even=2;

    int odd;
    (n%2==0)?odd=n-1:odd=n-2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout<<even<<" ";
            even+=2;
        }
        else{
            cout<<odd<<" ";
            odd-=2;
        }
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
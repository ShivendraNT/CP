#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int sum=0;
    int neg=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==-1) neg++;
        sum+=x;
    }
    if(sum>=0 && neg%2==0){
        cout<<0<<endl;
        return;
    }
    else if(sum>=0){
        cout<<1<<endl;
        return;
    }
    else{
        int ans=-1*sum;
        if(ans%2==0){
            ans/=2;
        }
        else{
            ans/=2;
            ans++;
        }
        neg-=ans;
        if(neg%2!=0){
            ans++;
        }
        cout<<ans<<endl;
        return;
    }
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
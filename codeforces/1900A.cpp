#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int maxpool=0;
    int pool=0;
    bool inf=false;
    int ans=0;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='.'){
            pool++;
            ans++;
        }
        else{
            maxpool=max(maxpool,pool);
            pool=0;
        }
        if(maxpool>=3){
            inf=true;
        }
    }
    maxpool=max(maxpool,pool);
    if(maxpool>=3){
            inf=true;
    }
    if(inf){
        cout<<2<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;   // remove if single test case
    for (int i = 0; i < t; i++) solve();
    return 0;
}
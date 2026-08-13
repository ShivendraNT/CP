#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    char c;
    cin>>c;
    string s;
    cin>>s;
    if(c=='g'){
        cout<<0<<'\n';
        return;
    }
    vector<int> greens;
    for(int i=0;i<n;i++){
        if(s[i]=='g'){
            greens.push_back(i);
        }
    }
    int maxdist=0;
    for(int i=0;i<n;i++){
        if(s[i]==c){
            auto it=lower_bound(greens.begin(),greens.end(),i);
            if(it==greens.end()){
                int dist=(n-i+greens[0]);
                maxdist=max(dist,maxdist);
            }
            else{
                maxdist=max(maxdist,*it-i);
            }
        }
    }
    cout<<maxdist<<'\n';
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
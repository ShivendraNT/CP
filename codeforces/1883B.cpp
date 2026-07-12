#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    unordered_map<char,int> mpp;
    string s;
    cin>>s;
    if(k==n-1){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    int odd_cnt = 0;
    for(auto it:mpp){
        if(it.second%2==1){
            odd_cnt++;
        }
    }
    if (k >= odd_cnt-1 && k <= n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
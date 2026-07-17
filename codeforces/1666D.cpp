#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s,target;
    cin>>s>>target;
    unordered_map<char,int> mpp;
    int ssize=s.size();
    int targetsize=target.size();
    int i=ssize-1;
    int j=targetsize-1;
    while(i>=0&&j>=0){
        if(s[i]==target[j]){
            i--;
            j--;
            if(j>=0&&mpp.find(target[j])!=mpp.end()){
                cout<<"NO"<<'\n';
                return;
            }
        }
        else{
            mpp[s[i]]=1;
            i--;
        }
    }
    if(j<0){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
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
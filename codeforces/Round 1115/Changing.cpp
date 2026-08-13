#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<0<<endl;
        return;
    }
    int total0 = 0, total1 = 0;
    for(char c : s) {
        if(c == '0') total0++;
        else total1++;
    }
    
    if(abs(total0 - total1) > 2) {
        cout << -1 << '\n';
        return;
    }
    
    int needzero=0;
    int needone=0;

    // Check the zeros and ones that need to be removed to make string alternate
    char prev=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==prev){
            if(s[i]=='0'){
                needzero++;
            }
            else{
                needone++;
            }
        }
        else{
            prev=s[i];
        }
    }
    int ans = max(needzero + needone, 2 * max(needzero, needone) - 1);
    cout << ans << '\n';
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
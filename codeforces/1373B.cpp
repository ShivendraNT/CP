#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin>>s;
    int moves=0;
    stack<char> st;
    for(char c:s){
        if(c=='0'){
            if(!st.empty() && st.top()=='1'){
                moves++;
                st.pop();
            }
            else{
                st.push('0');
            }
        }
        else {
            if(!st.empty() && st.top()=='0'){
                moves++;
                st.pop();
            }
            else{
                st.push('1');
            }
        }
    }
    if(moves%2==0){
        cout<<"NET"<<"\n";
    }
    else{
        cout<<"DA"<<"\n";
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
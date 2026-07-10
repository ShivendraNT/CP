#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;
    string y;
    cin>>y;
    int op=0;
    while(x.size()<y.size()){
        x+=x;
        op++;
    }
    if(x.find(y) != string::npos){
        cout<<op<<endl;
        return;
    }
    x+=x;
    op++;
    if(x.find(y) != string::npos){
        cout<<op<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;  
    for (int i = 0; i < t; i++) solve();
    return 0;
}
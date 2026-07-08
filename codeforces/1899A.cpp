#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    if(n%3==0){
        cout<<"Second"<<endl;
    }
    else{
        cout<<"First"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;   
    for (int i = 0; i < t; i++) solve();
    return 0;
}
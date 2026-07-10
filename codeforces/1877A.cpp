#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<-1*sum<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;  
    for (int i = 0; i < t; i++) solve();
    return 0;
}
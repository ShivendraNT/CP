#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    bool even=false;
    int x;
    cin>>x;
    if(x%2==0){
        even=true;
    }
    int elem=1;
    int steps=0;
    for(int i=1;i<n;i++){
        cin>>x;
        if(x%2==0 && even){
            elem++;
        }
        else if(x%2!=0 && !even){
            elem++;
        }
        else{
            if(elem>1){
                steps+=(elem-1);
            }
            elem=1;
            even = (x % 2 == 0);
        }
    }
    if (elem > 1) {
        steps += (elem - 1);
    }
    cout<<steps<<endl;
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
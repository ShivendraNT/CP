#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> gasstations(n);
    for(int i=0;i<n;i++){
        cin>>gasstations[i];
    }
    int maxdiff=0;
    maxdiff=max(maxdiff,gasstations[0]);
    for(int i=1;i<n;i++){
        maxdiff=max(maxdiff,gasstations[i]-gasstations[i-1]);
    }
    maxdiff=max(maxdiff,(k-gasstations[n-1])*2);
    cout<<maxdiff<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;   
    for (int i = 0; i < t; i++) solve();
    return 0;
}
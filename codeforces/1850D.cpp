#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int maxlen=0;
    int len=1;
    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]<=k){
            len++;
        }
        else{
            maxlen=max(maxlen,len);
            len=1;
        }
    }
    maxlen=max(maxlen,len);
    cout<<n-maxlen<<'\n';
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
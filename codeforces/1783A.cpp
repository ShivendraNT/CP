#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    reverse(nums.begin(),nums.end());
    reverse(nums.begin()+1,nums.end());
    int sum=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]==sum){
            cout<<"NO"<<endl;
            return;
        }
        sum+=nums[i];
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
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
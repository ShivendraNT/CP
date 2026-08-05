#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<ll> temp=nums;
    sort(temp.begin(),temp.end());
    if(temp[0]!=0){
        cout<<-1<<'\n';
        return;
    }
    ll prev = temp[0];
    ll len = 1;
    ll sum = 0; 
    ll last = 0;
    unordered_map<ll,ll> mp;
    for(int i=1;i<n;i++){
        if(temp[i]==prev){
            len++;
        }
        else{
            ll num=temp[i]-sum;
            if(num%len!=0 || num/len<=last){
                cout<<-1<<'\n';
                return;
            }
            ll div=num/len;
            sum+=div*len;
            last=div;
            mp[prev]=div;
            prev=temp[i];
            len=1;
        }
    }
    mp[prev]=last+1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        cout<<mp[nums[i]]<<" ";
    }
    cout<<'\n';
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
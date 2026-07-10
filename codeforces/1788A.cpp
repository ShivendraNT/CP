#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int numtwo=0;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==2){
            numtwo++;
        }
        nums.push_back(x);
    }
    if(numtwo%2!=0){
        cout<<-1<<endl;
        return;
    }
    if(numtwo==0){
        cout<<1<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(nums[i]==2){
            numtwo-=2;
        }
        if(numtwo==0){
            cout<<i+1<<endl;
            return;
        }
    }
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
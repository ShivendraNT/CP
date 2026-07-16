#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<vector<ll>> reach(200001);

    for(ll x : nums){
        ll steps = 0;
        while(x > 0){
            reach[x].push_back(steps);
            steps++;
            x /= 2;
        }
    }
    ll mini = LLONG_MAX;
    for(int v = 1; v <= 200000; v++){         
        if((ll)reach[v].size() < k) continue; 
        ll sum = 0;
        for(int j = 0; j < k; j++) sum += reach[v][j];
        mini = min(mini, sum);
    }
    cout << mini << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
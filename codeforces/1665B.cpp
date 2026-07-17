#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    int max_count = 1;
    int current_count = 1;
    
    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i-1]) {
            current_count++;
        } else {
            max_count = max(max_count, current_count);
            current_count = 1;
        }
    }
    max_count = max(max_count, current_count);
    
    int ans = n - max_count;
    while(max_count < n) {
        max_count *= 2;
        ans++;
    }
    cout << ans << '\n';
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
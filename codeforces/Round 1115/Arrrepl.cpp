#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> diff(n - 1);
    for(int i = 0; i < n - 1; i++){
        diff[i] = arr[i+1] - arr[i];
    }
    
    int i = 0;
    while(i < n - 1) {
        int j = i;
        while(j < n - 1 && (abs(diff[j]) % 2 == abs(diff[i]) % 2)) {
            j++;
        }
        sort(diff.begin() + i, diff.begin() + j);
        i = j;
    }
    
    for(int k = 1; k < n; k++){
        arr[k] = arr[k-1] + diff[k-1];
    }
    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }
    cout << "\n";
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sortcheck(vector<int> & elem,int n){
    for(int i=1;i<n;i++){
        if(elem[i]<elem[i-1]){
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin>>n;
    vector<int> elem(n);
    for(int i=0;i<n;i++){
        cin>>elem[i];
    }
    if(n==2){
        if(elem[0]<elem[1]){
            cout<<0<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
        return;
    }
    int inversions = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(elem[i] > elem[j]) inversions++;
        }
    }
    if(n % 2 == 0 && inversions % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    if(sortcheck(elem,n)){
        cout<<0<<"\n";
        return;
    }
    vector<int> seq;
    // Get the position of maximum
    int pos=0;
    int maxi=elem[0];
    for(int i=1;i<n;i++){
        if(elem[i]>maxi){
            maxi=elem[i];
            pos=i;
        }
    }
    if (pos == n - 1) pos--;

    seq.push_back(pos+1);
    int first_val = elem[pos];
    int next_val = elem[pos+1];
    elem.erase(elem.begin()+pos, elem.begin()+pos+2);
    elem.insert(elem.begin(), first_val);
    elem.push_back(next_val);
    int ops_limit = 4 * n;
    while(!sortcheck(elem,n)){
        pos=0;
        int mini=elem[0];
        for(int i=0;i<n-1;i++){
            if(elem[i]<mini){
                pos=i;
                mini=elem[i];
            }
        }
        seq.push_back(pos+1);
        first_val = elem[pos];
        next_val = elem[pos+1];
        elem.erase(elem.begin()+pos, elem.begin()+pos+2);
        elem.insert(elem.begin(), first_val);
        elem.push_back(next_val);
    }
    cout<<(int)seq.size()<<"\n";
    for(int i:seq){
        cout<<i<<" ";
    }
    cout<<"\n";
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        freq[a]++;
    }
    if(freq.size()>2){
        cout<<"NO"<<endl;
        return;
    }
    if(freq.size()==1){
        cout<<"YES"<<endl;
        return;
    }
    int first=0;
    for(auto it:freq){
        if(first==0){
            first=it.second;
        }
        else{
            if(abs(it.second-first)>1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;  
    for (int i = 0; i < t; i++) solve();
    return 0;
}
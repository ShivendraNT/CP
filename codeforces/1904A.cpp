#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

void solve() {
    int a,b;
    cin>>a>>b;
    int xk,yk;
    cin>>xk>>yk;
    int xq,yq;
    cin>>xq>>yq;
    // Calculate all 8 possibilities from king
    unordered_map<pair<int,int>,int,pair_hash> mpp;
    int y[]={-1,-1,1,1};
    int x[]={-1,1};
    for(int i=0;i<4;i++){
        int ynew=yk;
        int xnew=xk;
        if(i%2==0){
            ynew+=a*y[i];
            for(int j=0;j<2;j++){
                xnew+=b*x[j];
                mpp[{xnew,ynew}]=1;
                xnew=xk;
            }
        }
        else{
            xnew+=a*y[i];
            for(int j=0;j<2;j++){
                ynew+=b*x[j];
                mpp[{xnew,ynew}]=1;
                ynew=yk;
            }
        }
        
    }
    // Checking for queen
    int ans=0;
    for(int i=0;i<4;i++){
        int ynew=yq;
        int xnew=xq;
        if(i%2==0){
            ynew+=a*y[i];
            for(int j=0;j<2;j++){
                xnew+=b*x[j];
                if(mpp.find({xnew,ynew})!=mpp.end()){
                    ans++;
                }
                xnew=xq;
            }
        }
        else{
            xnew+=a*y[i];
            for(int j=0;j<2;j++){
                ynew+=b*x[j];
                if(mpp.find({xnew,ynew})!=mpp.end()){
                    ans++;
                }
                ynew=yq;
            }
        }
        
    }
    if (a == b) {
    ans /= 2;
    }
    cout << ans << endl;
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
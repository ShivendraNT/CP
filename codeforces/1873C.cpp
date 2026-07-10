#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int sum=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char c;
            cin>>c;
            if(c=='.') continue;
            if(i==0 || i==9){
                sum++;
            }
            else if(i==1 || i==8){
                if(j==0 || j==9){
                    sum++;
                }
                else{
                    sum+=2;
                }
            }
            else if(i==2 || i==7){
                if(j==0 || j==9){
                    sum++;
                }
                else if(j==1 || j==8){
                    sum+=2;
                }
                else{
                    sum+=3;
                }
            }
            else if(i==3 || i==6){
                if(j==0 || j==9){
                    sum++;
                }
                else if(j==1 || j==8){
                    sum+=2;
                }
                else if(j==2 || j==7){
                    sum+=3;
                }
                else{
                    sum+=4;
                }
            }
            else{
                if(j==0 || j==9){
                    sum++;
                }
                else if(j==1 || j==8){
                    sum+=2;
                }
                else if(j==2 || j==7){
                    sum+=3;
                }
                else if(j==3 || j==6){
                    sum+=4;
                }
                else{
                    sum+=5;
                }
            }
        }
    }
    cout<<sum<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;  
    for (int i = 0; i < t; i++) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
struct Node{
    int val;
    bool orpos;
};

vector<Node> tree;
vector<ll> a;

Node merge(Node L,Node R){
    Node next;
    if(L.orpos){
        next.val=L.val | R.val;
        next.orpos=!L.orpos;
    }
    else{
        next.val=L.val ^ R.val;
        next.orpos=!L.orpos;
    }
    return next;
}

void build(int node, int lo,int hi,bool orpos){
    if(lo==hi){
        Node next;
        next.orpos=orpos;
        next.val=a[lo];
        tree[node]=next;
        return;
    }
    ll mid=(hi-lo)/2+lo;
    build(2*node,lo,mid,!orpos);
    build(2*node+1,mid+1,hi,!orpos);
    Node next;
    next=merge(tree[2*node],tree[2*node+1]);
    tree[node]=next;
}

void update(int node,int pos,int c,int lo,int hi){
    if(lo==hi){
            tree[node].val=c;
            return;
        }
    int mid=(lo+hi)/2;
    if(pos<mid+1){
        update(2*node,pos,c,lo,mid);
    }
    else{
        update(2*node+1,pos,c,mid+1,hi);
    }
    tree[node]=merge(tree[2*node],tree[2*node+1]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    
    ll el = 1LL << n;
    tree.resize(4*el);
    a.resize(el);
    for(int i=0;i<el;i++){
        cin>>a[i];
    }
    if(n%2==0){
        build(1,0,el-1,true);
    }
    else{
        build(1,0,el-1,false);
    }
    for(int i=0;i<m;i++){
        int p,b;
        cin>>p>>b;
        update(1,p-1,b,0,el-1);
        cout<<tree[1].val<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/input.txt", "r", stdin);
    freopen("/Users/shivendranarayantripathi/Desktop/CP/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
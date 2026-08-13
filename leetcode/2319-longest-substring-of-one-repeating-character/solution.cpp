class Solution {
public:
    int n;
    struct Node{
        int pref;
        int suff;
        int best;
        char lc,rc;
        int len;
    };
    string s;
    vector<Node> tree;
    Node merge(Node L,Node R){
        Node res;
        res.len=L.len+R.len;
        res.lc=L.lc;
        res.rc=R.rc;
        res.best=max(L.best,R.best);
        if(L.rc==R.lc){
            res.best=max(res.best,L.suff+R.pref);
        }
        res.pref=L.pref;
        if(L.pref==L.len && L.rc == R.lc) res.pref+=R.pref;
        res.suff=R.suff;
        if(R.suff==R.len && R.lc==L.rc) res.suff+=L.suff;
        return res;
    }
    void build(int node,int lo,int hi){
        if(lo==hi){
            Node next;
            next.pref=1;
            next.suff=1;
            next.best=1;
            next.lc=s[lo];
            next.rc=s[lo];
            next.len=1;
            tree[node] = next;
            return;
        }
        int mid=(lo+hi)/2;
        build(2*node,lo,mid);
        build(2*node+1,mid+1,hi);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
    void update(int node,int pos,char c,int lo,int hi){
        if(lo==hi){
            tree[node].lc=c;
            tree[node].rc=c;
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
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n=s.size();
        this->s=s;
        tree.resize(4*n);
        build(1,0,n-1);
        vector<int> ans;
        for(int i=0;i<queryIndices.size();i++){
            update(1,queryIndices[i],queryCharacters[i],0,n-1);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};

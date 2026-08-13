class NumArray {
public:
    int n;
    vector<int> tree;
    vector<int> a;
    void build(int node,int lo,int hi){
        if(lo==hi){
            tree[node]=a[lo];
            return;
        }
        int mid=(lo+hi)/2;
        build(2*node,lo,mid);
        build(2*node+1,mid+1,hi);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    NumArray(vector<int>& nums) {
        a=nums;
        n=nums.size();
        tree.resize(4*n,0);
        build(1,0,n-1);
    }
    void up(int node,int pos,int lo,int hi,int val){
        if(lo==hi){
            tree[node]=val;
            return;
        }
        int mid=(lo+hi)/2;
        if(pos<mid+1){
            up(2*node,pos,lo,mid,val);
        }
        else{
            up(2*node+1,pos,mid+1,hi,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(int index, int val) {
        up(1,index,0,n-1,val);
    }
    
    int sum(int node,int lo,int hi,int ql,int qr){
        if(hi<ql || lo>qr){
            return 0;
        }
        else if(lo>=ql && hi<=qr){
            return tree[node];
        }
        int mid=(lo+hi)/2;
        return sum(2*node,lo,mid,ql,qr) + sum(2*node+1,mid+1,hi,ql,qr);
    }
    int sumRange(int left, int right) {
        return sum(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class Solution {
public:
    vector<long long> depth;
    vector<int>*par;

    long long getdepth(int n){
        if(depth[n]!=0) return depth[n];
        if((*par)[n]==-1) return depth[n]=1;
        return depth[n]=getdepth((*par)[n])+1;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long height=1;
        int n=parent.size();
        
        depth.assign(n,0);
        par=&parent;
        
        for(int i=0;i<n;i++){
            height = max(height, getdepth(i));
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(long long)nums[i]*(height-depth[i]+1);
        }
        return ans;
    }
};

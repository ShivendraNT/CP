class Solution {
public:
    vector<long long> bit;
    int n;
    void update(int i,long long delta){
        while(i<=n){
            bit[i]+=delta;
            i+=i&(-i);
        }
    }

    long long query(int i){
        long long s=0;
        while(i>0){
            s+=bit[i];
            i-=i&(-i);
        }
        return s;
    }

    long long range(int l,int r){
        return query(r)-query(l-1);
    }
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        vector<int> b=nums;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int i=0;i<n;i++){
            nums[i]=lower_bound(b.begin(),b.end(),nums[i])-b.begin()+1;
        }
        bit.assign(n+2,0);
        long long inv=0;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            inv=query(nums[i]-1);
            ans.push_back(inv);
            update(nums[i],1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

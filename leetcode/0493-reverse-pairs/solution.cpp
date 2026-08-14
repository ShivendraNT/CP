class Solution {
public:

    vector<long long> bit;
    int n;


    long long query(int i){
        long long s=0;
        while(i>0){
            s+=bit[i];
            i-=i&(-i);
        }
        return s;
    }

    void update(int i,long long delta){
        while(i<=n){
            bit[i]+=delta;
            i+=i&(-i);
        }
    }

    int reversePairs(vector<int>& nums) {
        
        vector<long long> b;
        for(int x : nums){ b.push_back(x); b.push_back(2LL*x); }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        n=b.size();
        bit.resize(n+2,0);

        auto rk = [&](long long v){
    return (int)(lower_bound(b.begin(), b.end(), v) - b.begin()) + 1;
};
        long long inv=0;
        int m = nums.size();
        for(int i=m-1;i>=0;i--){
            inv += query(rk(nums[i]) - 1);
            update(rk(2LL * nums[i]), 1);
        }
        return inv;
    }
};

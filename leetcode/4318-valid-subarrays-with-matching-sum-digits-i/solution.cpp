class Solution {
public:
    bool check(long long num, int x) {
        if (num % 10 != x) return false;
        while (num >= 10) {
            num /= 10;
        }
        return num == x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long> prefixsum;
        prefixsum.push_back(0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefixsum.push_back((long long)prefixsum.back()+(long long)nums[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(check(prefixsum[i]-prefixsum[j],x)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

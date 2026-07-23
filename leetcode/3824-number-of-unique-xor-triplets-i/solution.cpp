class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        long long n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int bits = 64 - __builtin_clzll(n);
        return 1LL << bits; 
    }
};

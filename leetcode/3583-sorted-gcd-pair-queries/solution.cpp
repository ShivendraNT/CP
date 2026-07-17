class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAX=-1;
        for(int i:nums){
            MAX=max(MAX,i);
        }
        vector<int> freq(MAX+1, 0);
        for(int x : nums) freq[x]++;
        vector<long long> cnt(MAX+1, 0);
        for(int g = 1; g <= MAX; g++)       
            for(int m = g; m <= MAX; m += g) 
                cnt[g] += freq[m];
        vector<long long> exact(MAX+1,0);
        for(int g=1;g<=MAX;g++){
            long long c=cnt[g];
            exact[g]=c*(c-1)/2;
        }
        for(int g=MAX;g>=1;g--){
            for(int m=2*g;m<=MAX;m+=g){
                exact[g]-=exact[m];
            }
        }
        vector<long long> prefix(MAX+1, 0);
        prefix[0] = 0;
        for(int g = 1; g <= MAX; g++)
            prefix[g] = prefix[g-1] + exact[g];
        vector<int> ans;
        for(long long q : queries){
            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(g);
        }
    return ans;
    }
};

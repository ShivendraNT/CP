class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> count;
        for(int i:nums){
            count[i]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto& it: count){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;--i){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};

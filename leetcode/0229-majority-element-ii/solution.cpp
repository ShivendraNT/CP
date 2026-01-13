class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        vector<int> ans;
        int n=nums.size();
        for (int i:nums){
            counter[i]++;
        }
        for (auto it:counter){
            if(it.second>(int)n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

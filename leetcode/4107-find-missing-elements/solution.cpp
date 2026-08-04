class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxelem=*max_element(nums.begin(),nums.end());
        int minelem=*min_element(nums.begin(),nums.end());
        vector<int> ans={};
        vector<bool> pres(maxelem-minelem,false);
        for(int i:nums){
            pres[i-minelem]=true;
        }
        for(int i=0;i<pres.size();i++){
            if(!pres[i]){
                ans.push_back(i+minelem);
            }
        }
        return ans;
    }
};

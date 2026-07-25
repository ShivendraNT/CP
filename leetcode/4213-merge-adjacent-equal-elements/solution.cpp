class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        ans.push_back(nums[0]);
        long long n=nums.size();
        long long i=1;
        while(i<n){
            long long number=nums[i];
            while(ans.size()>0&&ans.back()==number){
                ans.pop_back();
                number*=2;
            }
            ans.push_back(number);
            i++;
        }
        return ans;
    }
};

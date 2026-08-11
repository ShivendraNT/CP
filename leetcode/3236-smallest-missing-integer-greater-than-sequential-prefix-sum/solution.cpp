class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int n=nums.size();

        for(int i=0;i<n;i++) cnt[nums[i]]++;
        int maxsum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                maxsum+=nums[i];
            }
            else{
                break;                            
            }
        }
        while(cnt.find(maxsum)!=cnt.end()){
            maxsum++;
        }
        return maxsum;
    }
};

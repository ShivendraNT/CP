class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bool pairseen[2048]={false};
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairseen[nums[i]^nums[j]]=true;
            }
        }
        bool tripleseen[2048]={false};
        for(int p=0;p<2048;p++){
            if(pairseen[p]){
                for(int i=0;i<n;i++){
                    tripleseen[p^nums[i]]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<2048;i++){
            if(tripleseen[i]){
                ans++;
            }
        }
        return ans;
    }
};

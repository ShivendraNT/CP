class Solution {
public:
    vector<int> getrange(vector<int>&nums,int &maxrange){
        
        vector<int> ranges;
        for(int i:nums){
            int maxelem=0;
            int minelem=9;
            if(i==0){
                ranges.push_back(0);
                continue;
            }
            while(i!=0){
                int dig=i%10;
                i/=10;
                if(dig>maxelem) maxelem=dig;
                if(dig<minelem) minelem=dig;
            }
            if(maxelem-minelem>maxrange) maxrange=maxelem-minelem;
            ranges.push_back(maxelem-minelem);
        }
        return ranges;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxrange=0;
        vector<int> ranges=getrange(nums,maxrange);
        int sum=0;
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]==maxrange){
                sum+=nums[i];
            }
        }
        return sum;
    }
};

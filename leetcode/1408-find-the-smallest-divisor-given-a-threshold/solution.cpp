class Solution {
public:
    int div(vector<int> & nums, int div){
        int sum=0;
        for(int i:nums){
            if(i%div!=0){
                sum++;
            }
            sum+=i/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right= *max_element(nums.begin(),nums.end());
        int ans=0;
        while(left<=right){
            int mid=(right-left)/2+left;
            
            int sum=div(nums,mid);
            if(sum<=threshold){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};

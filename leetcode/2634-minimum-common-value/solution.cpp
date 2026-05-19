class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]>nums2[j]){
                while(j<nums2.size()-1&&nums2[j]==nums2[j+1]){
                    j++;
                }
                j++;
            }
            else{
                while(i<nums1.size()-1&&nums1[i]==nums1[i+1]){
                    i++;
                }
                i++;
            }
        }
        return -1;
    }
};

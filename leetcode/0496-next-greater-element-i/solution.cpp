class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> elem;
        stack<int> st;
        int n=nums2.size()-1;
        for(int i=n;i>=0;i--){
            if(st.empty()){
                elem[nums2[i]]=-1;
            }
            else if((st.top()>nums2[i])){
                elem[nums2[i]]=st.top();
            }
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    elem[nums2[i]]=-1;
                }
                else{
                    elem[nums2[i]]=st.top();
                }
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=elem[nums1[i]];
        }
        return nums1;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty() || st.top()>nums[i]){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=-1;
            }
            else if(st.top()>nums[i]){
                res[i]=st.top();
            }
            else{
                while(!st.empty()&&st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    res[i]=-1;
                }
                else{
                    res[i]=st.top();
                }
            }
            st.push(nums[i]);
        }
        return res;
    }
};

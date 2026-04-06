class Solution {
public:
    int shipdays(vector<int> &weights,int w){
        int sum=0;
        int ans=1;
        for(int i:weights){
            sum+=i;
            if(sum>w){
                sum=i;
                ans++;
                continue;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        for(int i:weights){
            right+=i;
        }
        int ans=0;
        while(left<=right){
            int mid=(right-left)/2+left;
            int w=shipdays(weights,mid);
            if(w<=days){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};

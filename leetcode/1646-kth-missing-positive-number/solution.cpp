class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=0;
        if(arr[0]!=1){
            ans+=(arr[0]-1);
            if(ans>=k) return k;
        }
        k-=ans;
        int prev=arr[0];
        for(int i=1;i<arr.size();i++){
            ans=(arr[i]-prev-1);
            if(ans>=k){
                return prev+k;
            }
            prev=arr[i];
            k-=ans;
        }
        int n=arr.size()-1;
        return arr[n]+k;
    }
};

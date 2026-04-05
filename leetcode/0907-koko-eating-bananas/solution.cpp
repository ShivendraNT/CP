class Solution {
public:
    long long findhours(vector<int> & piles,int k){
        long long sum=0;
        for(int i:piles){
            if(i%k==0) sum+=(i/k);
            else sum+=(i/k)+1;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int p= *max_element(piles.begin(),piles.end());
        int right=p;
        int left=1;
        int ans=p;
        while(left<=right){
            int mid=(right-left)/2 + left;
            long long hours=findhours(piles,mid);
            if(hours<=h){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};

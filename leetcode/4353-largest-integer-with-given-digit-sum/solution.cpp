class Solution {
public:
    int largestInteger(int n, int s) {
        int maxsum=9*n;
        if(s>maxsum){
            return -1;
        }
        int ans=0;
        int curr=9;
        for(int i=0;i<n;i++){
            curr=min(curr,s);
            s-=curr;
            ans+=curr;
            ans*=10;
        }
        return ans/10;
    }
};

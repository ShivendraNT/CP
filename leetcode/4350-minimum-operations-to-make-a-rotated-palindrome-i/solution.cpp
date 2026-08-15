class Solution {
public:
    int totaladd(string s){
        int left=0;
        int right=s.size()-1;
        int ans=0;
        while(left<right){
            int diff=abs((int)s[right]-(int)s[left]);
            ans+=min(diff,26-diff);
            left++;
            right--;
        }
        return ans;
    }
    int minOperations(string s) {

        int n=s.size();
        int minop=INT_MAX;
        for(int i=0;i<n;i++){
            int op=i+totaladd(s);
            minop=min(minop,op);

            s=s.substr(1)+s[0];
        }
        return minop;
    }
};

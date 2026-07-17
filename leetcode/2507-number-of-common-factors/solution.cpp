class Solution {
public:
    int commonFactors(int a, int b) {
        int ans=0;
        for(int i=1; i<=gcd(a,b); i++){
            if(gcd(a,b)%i==0) ans++;

        }
        return ans;
    }
};

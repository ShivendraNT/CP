class Solution {
public:
    long long maximumValue(long long n, long long s, long long m) {
        if(n==1){
            return s;
        }
        if(n%2!=0){
            n--;
        }
        long long inc=(n/2)*m;
        long long dec=((n/2)-1);
        return s+inc-dec;
    }
};

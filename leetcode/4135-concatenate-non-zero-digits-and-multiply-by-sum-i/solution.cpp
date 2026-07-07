class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long newnum=0;
        int mul=1;
        while(n>0){
            int dig=n%10;
            n/=10;
            while(dig==0){
                dig=n%10;
                n/=10;
            }
            newnum+=dig*mul;
            mul*=10;
            sum+=dig;
        }
        return newnum*sum;
    }
};

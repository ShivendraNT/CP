class Solution {
public:
    void dig(int n, int& greatest,int&second){
        int dig=0;
        while(n>0){
            dig=n%10;
            n/=10;
            if(dig>greatest){
                second=greatest;
                greatest=dig;
            }
            else if(dig>second){
                second=dig;
            }
        }
    }
    int maxProduct(int n) {
        int a=0;
        int b=0;
        dig(n,a,b);
        return a*b;
    }
};

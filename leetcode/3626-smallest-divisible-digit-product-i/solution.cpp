class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp=n;
        while(true){
            temp=n;
            int j=temp%10;
            temp/=10;
            int i=1;
            if(temp>0) i=temp%10;
            if((i*j)%t==0){
                return n;
            }
            n++;
        }
        return -1;
    }
};

class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int temp=n;
        while(temp>0){
            rev*=10;
            rev+=temp%10;
            temp/=10;
        }
        return abs(n-rev);
    }
};

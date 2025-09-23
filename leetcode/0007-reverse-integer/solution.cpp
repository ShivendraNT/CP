#include <limits>
class Solution {
public:
    int reverse(int x) {
        long long res=0;
        if(x==0 || x> pow(2,31)-1 || x< -pow(2,31)){
            return 0;
        }
        
        vector<int> digits;
        while(x!=0){
            digits.push_back(x%10);
            x=x/10;
        }
        for(int i:digits){
            res=res*10;
            res=res+i;
        }
        if (res>INT_MAX || res<INT_MIN){
            return 0;
        }
        return (int)res;
    }
};

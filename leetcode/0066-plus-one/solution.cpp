class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto n=digits.end() - 1;
        int rem=1;
        do{
            int sum= *n+rem;
            *n=sum%10;
            rem=sum/10;
            n=n-1;
        }while(rem==1 && n>=digits.begin());
        if (rem==1){
            digits.insert(digits.begin(),rem);
        }
        return digits;
    }
};

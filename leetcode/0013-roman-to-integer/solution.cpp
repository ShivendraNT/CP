class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        auto stringPtr=s.begin();
        for (;stringPtr<s.end();++stringPtr){
            if (*stringPtr=='M'){
                sum=sum+1000;
            }
            else if (*stringPtr=='D'){
                sum=sum+500;
            }
            else if (*stringPtr=='C'){
                if (*(stringPtr+1) =='D' || *(stringPtr+1) =='M'){
                    sum=sum-100;
                }
                else{
                    sum=sum+100;
                }}
            else if (*stringPtr=='L'){
                sum=sum+50;
            }
            else if (*stringPtr=='X'){
                if (*(stringPtr+1) =='L' || *(stringPtr+1) =='C'){
                    sum=sum-10;
                }
                else{
                    sum=sum+10;
                }}
            else if (*stringPtr=='V'){
                sum=sum+5;
            }
            else if (*stringPtr=='I'){
                if (*(stringPtr+1) =='V' || *(stringPtr+1) =='X'){
                    sum=sum-1;
                }
                else{
                    sum=sum+1;
                }}
            }
        
        return sum;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int num=n;
        for(int i=0;i<10;i++){
            vector<int> digits;
            while(num!=0){
                digits.push_back(num%10);
                num=num/10;
            }
            for(int i:digits){
                num=num+ i*i;
            }
            n=num;
        }
        if (n==1){
            return true;
        }
        return false;
    }
};

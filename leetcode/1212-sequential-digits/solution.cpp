class Solution {
public:
    int finddig(int num){
        int dig=0;
        while(num>0){
            dig++;
            num/=10;
        }
        return dig;
    }
    int makeseq(int digits,int starting){
        int num=0;
        int dig=starting;
        for(int i=0;i<digits;i++){
            num*=10;
            num+=dig;
            dig++;
        }
        return num;
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowdig=finddig(low);
        int highdig=finddig(high);
        vector<int> ans;
        for(int i=0;i<=highdig-lowdig;i++){
            for(int j=1;j<=10-i-lowdig;j++){
                int num=makeseq(lowdig+i,j);
                if(num<low){
                    continue;
                }
                else if(num>high){
                    break;
                }
                else{
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // array to keep track of bills
        int billcount[]={0,0};
        for(int i:bills){
            if(i==5){
                billcount[0]++;
            }
            else if(i==10){
                if(billcount[0]>0){
                    billcount[1]++;
                    billcount[0]--;
                }
                else{
                    return false;
                }
            }
            else{
                if(billcount[0]>0 && billcount[1]>0){
                    billcount[1]--;
                    billcount[0]--;
                }
                else if(billcount[0]>2){
                    billcount[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

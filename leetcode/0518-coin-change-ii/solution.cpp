class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> prev(amount+1, 0);
        prev[0]=1;
        int coin=coins[0];
        int amt=coin;
        while(coin<=amount){
            prev[coin]=1;
            coin+=amt;
        }
        for(int i=1;i<coins.size();i++){
            vector<unsigned int> curr(amount+1,0);
            curr[0]=1;
            for(int j=1;j<=amount;j++){
                unsigned int nottaken=prev[j];
                unsigned int taken=0;
                if(coins[i]<=j){
                    taken=curr[j-coins[i]];
                }
                curr[j]=(nottaken+taken);
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};

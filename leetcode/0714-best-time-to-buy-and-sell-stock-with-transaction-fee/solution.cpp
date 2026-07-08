class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int aheadnotbuy,aheadbuy,currbuy,currnotbuy;
        aheadnotbuy=aheadbuy=0;
        int n=prices.size();
        for(int ind=n-1;ind>=0;ind--){
            //sell
            currnotbuy=max(prices[ind]-fee+aheadbuy,aheadnotbuy);

            //buy
            currbuy=max(-prices[ind]+aheadnotbuy,aheadbuy);
            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;
        }
        return aheadbuy;
    }
};

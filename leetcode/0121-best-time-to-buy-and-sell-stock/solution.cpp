class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2){
            return 0;
        }
        int min_price=prices[0];
        int diff=prices[1]-prices[0];
        for (int price : prices){
            if (price<min_price){
                min_price=price;
            }
            else if (price-min_price>diff){
                diff=price-min_price;
            }
        }
        if (diff>0) return diff;
        else return 0;
    }
};
